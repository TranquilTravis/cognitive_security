
/*
 * Shah Nawaz Khan
 * shah-nawaz.khan@tu-ilmenau.de
 *
 * This application layer does not send real data. Instead it only send a request through the layers below to the MAC layer. The MAC
 * Layer creates a random amount of data packets (specified in .ini file) and attempts to send it to a destination
 */

#include "crAppLayer.h"

void crAppLayer::initialize()
{
    appTimer = NULL;
//    readyTimer = NULL;

    // STATISTICS
    appRequests = registerSignal("appRequests");
    appSuccess = registerSignal("appSuccess");
    txDataSignal = registerSignal("txDataSignal");
    txAckSignal = registerSignal("txAckSignal");
    rxDataSignal = registerSignal("rxDataSignal");
    rxAckSignal = registerSignal("rxAckSignal");
    endSignal = registerSignal("endSignal");

    myAddress = getParentModule()->par("address");
    ackEnabled = true;
    numberOfPackets = 10000;

    // get the neighbors list
    const char *dist = getParentModule()->par("neighbors");
    cStringTokenizer tokenizer(dist);
    while (tokenizer.hasMoreTokens())
        neighbors.push_back(atoi(tokenizer.nextToken()));

    destinationNode = 0;

// comment here
//    if ( strcmp(getParentModule()->getFullName(),"CR1") == 0 )
//    {
        // Boot the process scheduling the initial message as a self-message.
//        setSUTransmitTimer(0);   // First call to start a comm, delay between 1 and 5
//        endTimer = new cMessage("EndTimer");  // Start a new session
//        scheduleAt(20, endTimer);
//    }
//    else {
        setSUTransmitTimer(uniform(0, 1));
//        sendAppCheck(1.0);    //
//    }

}
void crAppLayer::handleMessage(cMessage *msg)
{
    if (msg == appTimer)  // start a new communication.
    {
        delete msg;
        appTimer = NULL;
        sendAppREQUEST();  // send a request for lower layer to ultimately send RTS packet
        setSUTransmitTimer(uniform(1.0, 2.0));
    }
//    else if (msg == readyTimer)  // start a new communication.
//    {
//        delete msg;
//        readyTimer = NULL;
//        sendReqReady();
//    }
    else if (msg->arrivedOn("ctrlLower$i"))  //Control Information from below
    {
        ctrlMsg *recMsg = check_and_cast<ctrlMsg *>(msg);
        switch(recMsg->getKind())
        {
            case AppREQUEST:
                //FIXME
                delete recMsg;
                break;
            case AppCONFIRMATION:
                appTimer = NULL;
                handleAppCONFIRMATION(recMsg);
                break;
            case TxSUCCESS:
                emit(appSuccess, 1);
                LOG("crAPPLayer-" << getIndex() <<": Successful Communication.");
                setSUTransmitTimer(1);
                delete recMsg;
//                emit(endSignal, simTime());
//                endSimulation();
                break;
            case TxFAIL:
                setSUTransmitTimer(1);
                delete recMsg;
                break;
//            case AppReqReady:
//                setSUTransmitTimer(0);
//                delete recMsg;
//                break;
            default:
                LOG("crAPPLayer-" << getIndex() << ": Unknown Message type");
                delete recMsg;
                break;
        }

    }
    else if(msg->arrivedOn("dataLower$i")) // data msg from outside world for me....
    {
        dataMsg *recMsg = check_and_cast<dataMsg *>(msg);
        switch(recMsg->getKind())
        {
            case DATA:
                handleData(recMsg);
                break;
            case ACK:
                handleACK(recMsg);
                break;
            default:
                LOG("AppLayer: Unknown Message type");
                delete recMsg;
                break;
        }
    }
    else
    {
        delete msg;
    }

}
void crAppLayer::setSUTransmitTimer(double startTime)
{
    if (appTimer == NULL)
    {
        appTimer = new cMessage("Apptimer");  // Start a new session
        scheduleAt((simTime()+uniform(startTime, startTime+0.1)), appTimer);
    }
}

//void crAppLayer::sendAppCheck(double startTime)
//{
//    if(readyTimer == NULL)
//    {
//        readyTimer = new cMessage("AppReady");
//        scheduleAt((simTime()+uniform(startTime, startTime+0.1)), readyTimer);
//    }
//}
//
//void crAppLayer::sendReqReady()
//{
//    char msgName[20];
//    sprintf(msgName, "ReqReady-%d", getIndex());
//    ctrlMsg *reqReady = new ctrlMsg(msgName);
//    reqReady->setKind(AppReqReady);
//    forwardCtrlMessage(reqReady);
//}

void crAppLayer::sendAppREQUEST()
{

    //// select a random destination from the neighbor list
    int selectedNeighbor = intuniform(0, neighbors.size()-1);
    destinationNode = neighbors.at(selectedNeighbor);
//    LOG(destinationNode); // comment

    LOG("Sending request for Application start");
    emit(appRequests, 1); // An attempt to start communication
    char msgName[20];
    sprintf(msgName, "AppReq-%d", getIndex());
    ctrlMsg *appRequest = new ctrlMsg(msgName);
    appRequest->setKind(AppREQUEST);
    appRequest->setDestination(destinationNode);
    forwardCtrlMessage(appRequest);
}

void crAppLayer::handleAppCONFIRMATION(ctrlMsg *msg)
{
    LOG("AppLayer: AppConfirmation received. Sending data...");
    sendData();
    delete msg;
    emit(appSuccess,1);
}

void crAppLayer::handleData(dataMsg *msg)
{
    delete msg;
    LOG("handle Data");
    emit(rxDataSignal, 1);
}

void crAppLayer::handleACK(dataMsg *msg)
{
    if (ackEnabled == false)
    {
        delete msg;
        return;
    }

    emit(rxAckSignal, 1);

    if (msg->getDestination() == myAddress &&
        msg->getNumberOfPackets() == numberOfPackets)
    {
        LOG("Data-ACK with seqNo: " << msg->getNumberOfPackets() << " received");
        numberOfPackets--;
        //disableACKTimeout();
    }
    delete msg;
}

void crAppLayer::forwardCtrlMessage(ctrlMsg *msg)
{
    LOG("Forwarding message " << msg << " on port " << "ctrlLower");
    send(msg, "ctrlLower$o");
}

void crAppLayer::forwardDataMessage(dataMsg *msg)
{
    LOG("Forwarding message " << msg << " on port " << "dataLower");
    emit(txDataSignal, 1);
    send(msg, "dataLower$o");
}

void crAppLayer::sendData()
{

    if (numberOfPackets > 0) // More data to send
    {
        dataMsg *msg = new dataMsg("Data");
        msg->setSource(myAddress);
        msg->setDestination(destinationNode);
        msg->setKind(DATA);
        msg->setNumberOfPackets(numberOfPackets++);
        msg->setByteLength(2000);
        forwardDataMessage(msg);
        //if (ackEnabled == true)
        //{
            //setACKTimeOut();
        //}
    }
}

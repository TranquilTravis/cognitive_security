/*
 * Shah Nawaz Khan
 * shah-nawaz.khan@tu-ilmenau.de
 *
 * This application layer does not send real data. Instead it only send a request through the layers below to the MAC layer. The MAC
 * Layer creates a random amount of data packets (specified in .ini file) and attempts to send it to a destination
 */

#ifndef CRAPPLAYER_H_
#define CRAPPLAYER_H_

#include "BaseAppLayer.h"
#include "ctrlMsg_m.h"
#include "dataMsg_m.h"

class crAppLayer : public BaseAppLayer
{
private:
    cMessage *appTimer;
//    cMessage *readyTimer; // add here
    simsignal_t appRequests, appSuccess;
    simsignal_t txDataSignal, txAckSignal;
    simsignal_t rxDataSignal, rxAckSignal;
    simsignal_t endSignal;
//    simsignal_t AppReqReady;
    int numberOfPackets;
    int myAddress;
    int destinationNode;
    std::vector<int> neighbors; // holds result
    bool ackEnabled;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void setSUTransmitTimer(double);
    void sendAppREQUEST();
    void handleAppCONFIRMATION(ctrlMsg *msg);
    void handleData(dataMsg *msg);
    void handleACK(dataMsg *msg);
    void forwardCtrlMessage(ctrlMsg *msg);
    void forwardDataMessage(dataMsg *msg);
    void sendData();
//    void sendAppCheck(double);   // add here, check if I can send app request
//    void sendReqReady();        // add here

};

Define_Module(crAppLayer);

#endif /* APPLICATIONLAYER_H_ */

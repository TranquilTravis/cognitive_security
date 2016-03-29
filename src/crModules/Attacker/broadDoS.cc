/*
 * broadDoS.cc
 *
 *  Created on: Nov 23, 2015
 *      Author: dongqi
 */


/*
 * It is intended to produce DoS attacker activity patterns. In prototype state, needs development
 */

#include "broadDoS.h"

broadDoS::broadDoS() {
}

broadDoS::~broadDoS() {
}

void broadDoS::initialize()
{
    starttime = par("starttime");
    stoptime = par("stoptime");
    attackStart = registerSignal("attackStart");
    attackEnd = registerSignal("attackEnd");
    apptimer = eot = datatimer = NULL;

// defined in omnetpp.ini file
    totalChannels = getParentModule()->getParentModule()->par("totalChannels");
    attack_hop = par("Attack_hop");
    bool status = getParentModule()->par("AttackEnabled");
//  status only used for set timer
    State = "IDLE";

//    Channel = getParentModule()->par("Channel");
 //       Channel = 1;
        //idleDuration = exponential(.3);
        //busyDuration = 1 - idleDuration;
        Color = "red";
        idleDuration = 0.10;
        busyDuration = 0.90;

    LOG("Initialize: start time is "<<starttime);

    updateGUI(-1,-1);

    if ( status == true){
         setTimer(starttime);
         LOG("Initialize attack");
    }

}

void broadDoS::handleMessage(cMessage *msg)
{
    if(msg == apptimer)
    {
        if (attack_hop == true) {
           Channel = intuniform(0, totalChannels-1)+1;
           LOG("ATTACK: myChannel = "<<Channel);
        }
        State = "Tx";
        delete msg;  apptimer = NULL;
        dataMsg *msg = new dataMsg("PUSTART");
        msg->setKind(PUSTART);
        msg->setProposedChannel(Channel);
        msg->setSource(0);

        sendAttack();
        broadcast(msg);
        scheduleEot();
        LOG("Send PUSTART. Start Attack.");
        std::string display = "i=device/antennatower,"+Color+",40";
        this->getParentModule()->setDisplayString(display.c_str());

        // reset duration of next comm. 60% duty cycle
        //idleDuration = exponential(0.3);
        //if(idleDuration > 1)
            //idleDuration = 1;
        //busyDuration = 1 - idleDuration;
    }
    else if (msg == datatimer)
    {
        delete msg;  datatimer = NULL;
        dataMsg *msg = new dataMsg("PUDATA");
        msg->setKind(PUDATA);
        msg->setProposedChannel(Channel);
        msg->setSource(0);
        broadcast(msg);
        sendAttack();
        LOG("Sending PUDATA. Attack Channel = "<<Channel);
        std::string display = "i=device/antennatower,"+Color+",40";
        this->getParentModule()->setDisplayString(display.c_str());
    }
    else if (msg == eot)  // Signal end of PU transmission
    {
        State = "IDLE";
        delete msg; eot = NULL;
        datatimer = NULL;
        dataMsg *puEnd = new dataMsg("PUEND");
        puEnd->setKind(PUEND);
        puEnd->setProposedChannel(Channel);
        broadcast(puEnd);

        setTimer(0.0);  // Schedule another PU transmission.
        LOG("Sending PUEND. Data transmission done.");
        this->getParentModule()->setDisplayString("i=device/antennatower");
    }
    else
    {
        //ev<<"Unknown Message at PU HandleMessage"<<endl;
        delete msg;
    }
}

void broadDoS::setTimer(double start)
{
    cancelAndDelete(datatimer);
    emit(attackStart, 1); // An attempt to start PU
    apptimer = new timerMsg("timer");
    scheduleAt(start + simTime()+ uniform(idleDuration*0.8,idleDuration*1.2), apptimer);
//    updateGUI(simTime().dbl()+ idleDuration,Channel);
    if (simTime() > stoptime) {
        cancelAndDelete(apptimer);
        cancelAndDelete(datatimer);
        cancelAndDelete(eot);
        apptimer = datatimer = eot = NULL;
    }
}

void broadDoS::sendAttack()
{
    datatimer = new timerMsg("data");
    LOG("Sending Attack Data at."<<simTime());
    scheduleAt(simTime()+ 0.1, datatimer);
}

void broadDoS::broadcast(dataMsg *msg)
{
    for ( int x=0; x<gateSize("radio"); x++)
    {
           dataMsg *copy = (dataMsg *) msg->dup();
           send(copy, "radio$o", x);
    }
    delete msg;
}

void broadDoS::scheduleEot()
{
    emit(attackEnd, 1); // An attempt to end PU
    eot = new cMessage("PUEnd");
    scheduleAt(simTime() + uniform(busyDuration*0.8,busyDuration*1.2), eot);
//    updateGUI(simTime().dbl()+ idleDuration,Channel);
}

void broadDoS::updateGUI(double time, int chID)
{
    // GUI changes
    std::stringstream sstr;
    sstr << "i=shah/antenna," << colorMap[chID] << ",40;t=Ch: " << chID
    << "\nNext:" << time << " State: " << State;
    //std::string str1 = sstr.str();
    //this->getParentModule()->setDisplayString(str1.c_str());
}





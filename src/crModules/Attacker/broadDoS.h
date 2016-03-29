/*
 * broadDoS.h
 *
 *  Created on: Nov 23, 2015
 *      Author: dongqi
 */

#ifndef BROADDOS_H_
#define BROADDOS_H_

#include "dataMsg_m.h"
#include "timerMsg_m.h"
#include "Logging.h"

class broadDoS : public cSimpleModule{
public:
    broadDoS();
    virtual ~broadDoS();
protected:
    virtual void handleMessage(cMessage *msg);
    virtual void initialize();
    void setTimer(double start);
    void broadcast(dataMsg *msg);
    void scheduleEot();
    void sendAttack();

private:
    void updateGUI(double time, int chID);
    cMessage *apptimer, *eot;
    cMessage *datatimer;
    simsignal_t attackStart, attackEnd;
    std::map<int, std::string> colorMap;
    std::string State;
    std::string Color;
    int totalChannels, Channel;
    double idleDuration, busyDuration; //arrivalRate, txDuration;
    double starttime,stoptime;
    bool attack_hop;
};

Define_Module(broadDoS);


#endif /* BROADDOS_H_ */

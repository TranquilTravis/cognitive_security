

#ifndef BASEATTACKER_H_
#define BASEATTACKER_H_

#include<omnetpp.h>
#include "ctrlMsg_m.h"
#include "dataMsg_m.h"
#include "timerMsg_m.h"

class BaseAttacker : public cSimpleModule {
public:
        BaseAttacker();
        virtual ~BaseAttacker();
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(BaseAttacker);

#endif /* ATTACKER_H_ */

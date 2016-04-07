/*
 * ChTimer.h
 *
 *  Created on: Mar 20, 2016
 *      Author: dongqi
 */

#ifndef CHTIMER_H_
#define CHTIMER_H_

// in simtime_t.h
// typedef double         simtime_t;

class chTimer{
    public:
        chTimer();
        ~chTimer();

        void initialize();
        int getState();
        simtime_t getRecord();
        void setState(int flag);
        void resetRecord();
        void resetCh();
    private:
        simtime_t lastRecord;
        int state;
};

chTimer::chTimer(){}

chTimer::~chTimer(){}

void chTimer::initialize()
{
    lastRecord = 0.0;
    state = 0;
}

int chTimer::getState()
{
    return state;
}

simtime_t chTimer::getRecord()
{
    return lastRecord;
}

void chTimer::setState(int flag)
{
    state = flag;
    lastRecord = simTime();
}

void chTimer::resetRecord()
{
    lastRecord = simTime();
}

void chTimer::resetCh()
{
    if (simTime() > lastRecord + 0.02) {
        ev<<"State has been reset to 0\n";
        ev<<"Last record time is "<<lastRecord<<"\n";
        state = 0;
        lastRecord = simTime();
    }
    else {
        ev<<"State has not been reset to 0\n";
        ev<<"Last record time is "<<lastRecord<<"\n";
    }
}






#endif /* CHTIMER_H_ */

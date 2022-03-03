#pragma once 
#define EVENTTRACKER_H

#include "ArrayQueue.h"
#include "PriorityQueue.h"

class EventTracker{

private:
    int time, duration;
    bool type;

public:
    EventTracker();
    EventTracker(int newTime, int newDuration, bool newType);
    int getTime();
    int getDuration();
    bool getType();
    void setTime(int newTime);
    void setDuration(int newDuration);
    void setType(bool newType);
    bool operator < (EventTracker rhs); // returns the person w the lower time but greater priority


};






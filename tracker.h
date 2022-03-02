#pragma once 
#define TRACKER_H

#include "ArrayQueue.h"
#include "PriorityQueue.h"

class Tracker{

private:
    int time, duration;
    bool type;

public:
    Tracker();
    Tracker(int newTime, int newDuration, bool newType);
    int getTime();
    int getDuration();
    bool getType();
    void setTime(int newTime);
    void setDuration(int newDuration);
    void setType(bool newType);
    bool operator < (Tracker person1, Tracker person2); // returns the person w the lower time but greater priority


};






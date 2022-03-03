#pragma once 
#define EVENTTRACKER_H

#include "ArrayQueue.h"
#include "PriorityQueue.h"

class EventTracker{

private:
    int time, departure;
    std::string type;

public:
    EventTracker();
    EventTracker(int newTime, int newDeparture, std::string newType);
    int getTime();
    int getDeparture();
    std::string getType();
    void setTime(int newTime);
    void setDeparture(int newDeparture);
    void setType(std::string newType);
    bool operator < (EventTracker rhs); // returns the person w the lower time but greater priority


};






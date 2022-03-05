#pragma once
#define EVENTTRACKER_H

#include <iostream>

class EventTracker{

private:
    int time, departure;
    std::string type;

public:
    EventTracker();
    EventTracker(int newTime, int newDeparture, std::string newType);
    int getTime() const;
    int getDeparture() const;
    std::string getType() const;
    void setTime(int newTime);
    void setDeparture(int newDeparture);
    void setType(std::string newType);
    bool operator < (const EventTracker& rhs); // based on time
};








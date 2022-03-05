#pragma once
#define EVENT_H

#include <iostream>

class Event{

private:
    int time;
    std::string type;

public:
    Event();
    Event(int newTime, std::string newType);
    int getTime() const;
    std::string getType() const;
    void setTime(int newTime);
    void setType(std::string newType);
    bool operator < (const Event& rhs); // based on time
};








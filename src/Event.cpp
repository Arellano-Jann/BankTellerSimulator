#include "../headers/Event.h"

Event :: Event()
    : time(0)
    , type("no type")
    {}
Event :: Event(int newTime, std::string newType)
    : time(newTime)
    , type(newType)
    {}
int Event :: getTime() const{ return time; }
std::string Event :: getType() const{ return type; }
void Event :: setTime(int newTime){ time = newTime; }
void Event :: setType(std::string newType){ type = newType; }
bool Event :: operator <(const Event& rhs){
    if (time < rhs.getTime()) return true;
    return false;
}
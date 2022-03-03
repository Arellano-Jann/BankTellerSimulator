#include "EventTracker.h"

EventTracker :: EventTracker(){
        time = 0;
        duration = 0;
        type = false;
}
EventTracker :: EventTracker(int newTime, int newDuration, bool newType){
    time = newTime;
    duration = newDuration;
    type = newType;
}
int EventTracker :: getTime(){
    return time;
}
int EventTracker :: getDuration(){
    return duration;
}
bool EventTracker :: getType(){
    return type;
}
void EventTracker :: setTime(int newTime){
    time = newTime;
}
void EventTracker :: setDuration(int newDuration){
    duration = newDuration;
}
void EventTracker :: setType(bool newType){
    type = newType;
}
bool EventTracker :: operator <(EventTracker rhs){
    if(rhs.getTime() < time){
        return true;
    } else {
        return false;
    }
}
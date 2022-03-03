#include "tracker.h"

Tracker :: Tracker(){
        time = 0;
        duration = 0;
        type = false;
}
Tracker :: Tracker(int newTime, int newDuration, bool newType){
    time = newTime;
    duration = newDuration;
    type = newType;
}
int Tracker :: getTime(){
    return time;
}
int Tracker :: getDuration(){
    return duration;
}
bool Tracker :: getType(){
    return type;
}
void Tracker :: setTime(int newTime){
    time = newTime;
}
void Tracker :: setDuration(int newDuration){
    duration = newDuration;
}
void Tracker :: setType(bool newType){
    type = newType;
}
bool Tracker :: operator <(Tracker person1){
    if(person1.getTime() < time){
        return true;
    } else {
        return false;
    }
}
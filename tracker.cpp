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
void Tracker :: setType(int newTime){
    time = newTime;
}
void Tracker :: setDuration(int newDuration){
    duration = newDuration;
}
void setType(bool newType){
    type = newType;
}
Tracker Tracker :: operator <(Tracker person1, Tracker person2){
    if(person1.getTime() < person2.getTime()){
        return person1;
    } else {
        return person2;
    }
}
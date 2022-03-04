#include "../headers/EventTracker.h"

EventTracker :: EventTracker(){
        time = 0;
        departure = 0;
        type = false;
}
EventTracker :: EventTracker(int newTime, int newDeparture, std::string newType){
    time = newTime;
    departure = newDeparture;
    type = newType;
}
int EventTracker :: getTime() const{
    return time;
}
int EventTracker :: getDeparture() const{
    return departure;
}
std::string EventTracker :: getType() const{
    return type;
}
void EventTracker :: setTime(int newTime){
    time = newTime;
}
void EventTracker :: setDeparture(int newDeparture){
    departure = newDeparture;
}
void EventTracker :: setType(std::string newType){
    type = newType;
}
bool EventTracker :: operator <(const EventTracker& rhs){
    // if(rhs.getTime() < time) return true;
    if(time < rhs.getTime()) return true;
    return false;
}


// #include "EventTracker.h"

// EventTracker :: EventTracker(){
//         arrival = 0;
//         departure = 0;
//         type = "";
// }
// EventTracker :: EventTracker(int newArrival, int newDeparture, std::string newType){
//     arrival = newArrival;
//     departure = newDeparture;
//     type = newType;
// }
// int EventTracker :: getArrival(){
//     return arrival;
// }
// int EventTracker :: getDeparture(){
//     return departure;
// }
// std::string EventTracker :: getType(){
//     return type;
// }
// void EventTracker :: setArrival(int newArrival){
//     arrival = newArrival;
// }
// void EventTracker :: setDeparture(int newDeparture){
//     departure = newDeparture;
// }
// void EventTracker :: setType(std::string newType){
//     type = newType;
// }
// bool EventTracker :: operator <(EventTracker rhs){
//     if(rhs.getTime() < ){
//         return true;
//     } else {
//         return false;
//     }
// }
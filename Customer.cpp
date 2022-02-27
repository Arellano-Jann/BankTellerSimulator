#include "Customer.h"

Customer::Customer(int arrivalTime, int waitingTime)
	: arrivalTime(arrivalTime)
	, waitingTime(waitingTime)
{}

	void Customer::setArrivalTime(int newTime){
		arrivalTime = newTime;
	}
	void Customer::setWaitingTime(int newTime){
		waitingTime = newTime;
	}
	int Customer::getArrivalTime(){
		return arrivalTime;
	}
	int Customer::getWaitingTime(){
		return waitingTime;
	}
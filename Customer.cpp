#include "Customer.h"

Customer::Customer(int arrivalTime, int transactionTime, int waitingTime)
	: arrivalTime(arrivalTime)
 	, transactionTime (transactionTime)
	, waitingTime (waitingTime)
{}

Customer::Customer()
	: arrivalTime(0)
	, waitingTime(0)
{}

	void Customer::setArrivalTime(int newTime){
		arrivalTime = newTime;
	}
	void Customer :: setTransactionTime(int newTime){
		transactionTime = newTime;
	}
	void Customer::setWaitingTime(int newTime){
		waitingTime = newTime;
	}
	int Customer::getArrivalTime() const{
		return arrivalTime;
	}
<<<<<<< HEAD
	int Customer :: getTransactionTime(){
		return transactionTime;
	}
	int Customer::getWaitingTime(){
=======
		return waitingTime;
	}

	bool Customer::operator <(const Customer& rhs){
    // if(rhs.getTime() < time) return true;
    if(arrivalTime < rhs.getArrivalTime()) return true;
    return false;
}
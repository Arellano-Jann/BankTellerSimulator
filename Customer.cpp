#include "Customer.h"

Customer::Customer()
	: arrivalTime(0)
	, transactionTime(0)
	, waitingTime(0)
{}
Customer::Customer(int arrivalTime, int transactionTime, int waitingTime)
	: arrivalTime(arrivalTime)
 	, transactionTime (transactionTime)
	, waitingTime (waitingTime)
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
	int Customer::getArrivalTime() {
		return arrivalTime;
	}
	int Customer :: getTransactionTime(){
		return transactionTime;
	}
	int Customer::getWaitingTime(){
		return waitingTime;
	}

	bool Customer::operator <(Customer& rhs){
    // if(rhs.getTime() < time) return true;
    if(arrivalTime < rhs.getArrivalTime()) return true;
    return false;
}
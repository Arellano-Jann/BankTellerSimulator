#include "Customer.h"

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
	int Customer::getArrivalTime(){
		return arrivalTime;
	}
	int Customer :: getTransactionTime(){
		return transactionTime;
	}
	int Customer::getWaitingTime(){
		return waitingTime;
	}
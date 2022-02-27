#pragma once
#define CUSTOMER_H

class Customer{
private:
	int arrivalTime, waitingTime;
public:
	Customer(int arrivalTime, int waitingTime);
	void setArrivalTime(int newTime);
	void setWaitingTime(int newTime);
	int getArrivalTime();
	int getWaitingTime();
};

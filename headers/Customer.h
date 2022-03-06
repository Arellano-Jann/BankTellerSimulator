#pragma once
#define CUSTOMER_H

class Customer{
private:
	int arrivalTime, transactionTime, waitingTime;
public:
	Customer();
	Customer(int arrivalTime, int transactionTime, int waitingTime);
	void setArrivalTime(int newTime);
	void setWaitingTime(int newTime);
	void setTransactionTime(int newTime);
	int getArrivalTime();
	int getTransactionTime();
	int getWaitingTime();
	bool operator <(Customer& rhs);
};

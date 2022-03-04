#pragma once
#define CUSTOMER_H

class Customer{
private:
	int arrivalTime, waitingTime;
public:
	Customer(int arrivalTime, int waitingTime);
	Customer();
	void setArrivalTime(int newTime);
	void setWaitingTime(int newTime);
	int getArrivalTime() const;
	int getWaitingTime() const;
	bool operator < (const Customer& rhs);
};

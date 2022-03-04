#include "../headers/Customer.h"
#include "../headers/ArrayQueue.h"
#include "../headers/PriorityQueue.h"
#include "../headers/EventTracker.h"
#include <iostream> 
#include <string>
#include <fstream> 

using namespace std;

bool fileParser(string filename, PriorityQueue<Customer> &line);
bool depart(PriorityQueue<Customer> fileQueue, ArrayQueue<Customer> bankQueue);
bool arrive(PriorityQueue<Customer> fileQueue, ArrayQueue<Customer> bankQueue);
void output(PriorityQueue<EventTracker> EventQueue);

PriorityQueue<Customer> fileQueue; // initial queue
ArrayQueue<Customer> bankQueue; // bank line
PriorityQueue<EventTracker> EventQueue;
bool isTellerAvailable = true;
int currentTime = 0;


bool fileParser(string filename, PriorityQueue<Customer> &fileQueue){
	std::ifstream file(filename);
	if (file.is_open()){
		int arrivalTime, waitingTime;
		while (file >> arrivalTime >> waitingTime){
			Customer customer(arrivalTime, waitingTime); // if this doesn't work use getters and setters
			fileQueue.enqueue(customer);
		}
		file.close();
		return true;
	}
	file.close();
	return false;

}

bool depart(PriorityQueue<Customer> fileQueue, ArrayQueue<Customer> bankQueue){
	fileQueue.dequeue();
		if(!bankQueue.isEmpty()){
			Customer customer = bankQueue.peekFront(); // sets the front of the bank q to customer
			bankQueue.dequeue();
			currentTime += customer.getWaitingTime(); // calcs departure time
			if (currentTime < customer.getArrivalTime()) currentTime = customer.getArrivalTime();
			EventTracker departureEvent(currentTime, 0, "departure"); // creates a newEvent for each customers type
			EventQueue.enqueue(departureEvent);
			return true;
		}
	return false;
}
bool arrive(PriorityQueue<Customer> fileQueue, ArrayQueue<Customer> bankQueue){ // tbh i don't get the variables
	if (isTellerAvailable){
		currentTime = fileQueue.peekFront().getArrivalTime(); // sets the current time to arrival time of customer
		EventTracker arrivalEvent(currentTime, 0, "arrival");
		EventQueue.enqueue(arrivalEvent);
		currentTime += fileQueue.peekFront().getWaitingTime(); // sets the current time to actual departureTime
		EventTracker departureEvent(currentTime, 0, "departure"); // creates a newEvent for each customers type
		EventQueue.enqueue(departureEvent);
		fileQueue.dequeue(); // takes off the customer off the queue
		isTellerAvailable = false;
		return true;
	}

	bankQueue.enqueue(fileQueue.peekFront()); // assuming that the event has a proper arrival time etc
	int arrivalTime = fileQueue.peekFront().getArrivalTime();
	EventTracker arrivalEvent(arrivalTime, 0, "arrival");
	EventQueue.enqueue(arrivalEvent);
	return false;

// If the teller is available, set the customers arrival time to the current time and pop the prio queue.
		// When the customer departs, set the current time to += the waiting time and check if front of queue arrival time is less than the current time.
			// If front of queue arrival time is less than the current time, take the customer to the teller. This is done by setting the customer.arrivalTime to the current time and popping the front of the queue.
			// Else output “Waiting for customer” and then set customer.arrivalTime to the current time. Take the customer to the teller and pop the front of the queue.
}


void output(PriorityQueue<EventTracker> EventQueue){
	while (!EventQueue.isEmpty()){
		std::string eventType = EventQueue.peekFront().getType();
		int time = EventQueue.peekFront().getTime();
		std::cout << "Processing " << eventType << " at time: " << time << std::endl;
		EventQueue.dequeue();
	}
}
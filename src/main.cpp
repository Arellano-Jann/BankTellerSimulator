/**
 * @file main.cpp
 * @author Jann Arellano and Jenavieve Layosa
 * @brief 
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Pseudo Code

// Takes in file
// Puts each line into a priority queue.
// Has a while loop
	// The while loop iterates through based on if there is still events on the priority queue
	// If the teller is available, set the customers arrival time to the current time and pop the prio queue.
		// When the customer departs, set the current time to += the waiting time and check if front of queue arrival time is less than the current time.
			// If front of queue arrival time is less than the current time, take the customer to the teller. This is done by setting the customer.arrivalTime to the current time and popping the front of the queue.
			// Else output “Waiting for customer” and then set customer.arrivalTime to the current time. Take the customer to the teller and pop the front of the queue.
	// If the teller is not available, put in the back of queue
// Note that when popping prio queue, print a statement listing type of event and current time/arrival time.
#include <iostream> 
#include <string>
#include <fstream> 

#include "../headers/Customer.h"
#include "../headers/ArrayQueue.h"
#include "../headers/PriorityQueue.h"
#include "../headers/EventTracker.h"

bool fileParser(PriorityQueue<Customer> &line);
bool depart(ArrayQueue<Customer> bankQueue);
bool arrive(PriorityQueue<Customer> fileQueue, ArrayQueue<Customer> bankQueue);
void output(PriorityQueue<EventTracker> EventQueue);

PriorityQueue<Customer> fileQueue; // initial queue
ArrayQueue<Customer> bankQueue; // bank line
PriorityQueue<EventTracker> EventQueue;
bool isTellerAvailable = true;
int currentTime = 0;



int main(){

	std::string filename = "file.txt";
	std::cout << "What's the file name? ";
	std::cin >> filename;
	fileParser(fileQueue);
	if (true){
		{
			while (!fileQueue.isEmpty()){
				arrive(fileQueue, bankQueue);
			}
			while (!bankQueue.isEmpty()){
				depart(bankQueue);
			}
		}
	}
	output(EventQueue);
	return 0;
}
bool fileParser(PriorityQueue<Customer> &fileQueue){
	std::string filename = "file.txt";
	std::cout << "What's the file name? ";
	// std::cin >> filename;

	std::ifstream file(filename);
	// file.open(filename, std::ifstream::in);
	// if (file.is_open()){
		int arrivalTime, waitingTime;
		while (file >> arrivalTime >> waitingTime){
			Customer customer(arrivalTime, waitingTime); // if this doesn't work use getters and setters
			fileQueue.enqueue(customer);
		}
		// file.close();
		return true;
	// }
	file.close();
	return false;

}

bool depart(ArrayQueue<Customer> bankQueue){
		if(!bankQueue.isEmpty()){
			Customer customer = bankQueue.peekFront(); // sets the front of the bank q to customer
			currentTime += customer.getWaitingTime(); // calcs departure time
			if ( currentTime < customer.getArrivalTime() ) currentTime = customer.getArrivalTime();
			EventTracker departureEvent(currentTime, 0, "departure"); // creates a newEvent for each customers type
			EventQueue.enqueue(departureEvent);
			bankQueue.dequeue();
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
	if (!fileQueue.isEmpty()){
		bankQueue.enqueue(fileQueue.peekFront()); // assuming that the event has a proper arrival time etc
		int arrivalTime = fileQueue.peekFront().getArrivalTime();
		EventTracker arrivalEvent(arrivalTime, 0, "arrival");
		EventQueue.enqueue(arrivalEvent);
		fileQueue.dequeue(); // takes off the customer off the queue
		return true;
	}
	return false;
}


void output(PriorityQueue<EventTracker> EventQueue){
	while (!EventQueue.isEmpty()){
		std::string eventType = EventQueue.peekFront().getType();
		int time = EventQueue.peekFront().getTime();
		std::cout << "Processing " << eventType << " at time: " << time << std::endl;
		EventQueue.dequeue();
	}
}
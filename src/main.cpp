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

#include <iostream> 
#include <string>
#include <fstream> 

#include "../headers/Customer.h"
#include "../headers/ArrayQueue.h"
#include "../headers/PriorityQueue.h"
#include "../headers/Event.h"

bool fileParser(PriorityQueue<Customer> &fileQueue);
bool depart();
bool arrive();
void output(PriorityQueue<Event> EventQueue);

PriorityQueue<Customer> fileQueue;
ArrayQueue<Customer> bankQueue;
PriorityQueue<Event> EventQueue;
bool isTellerAvailable = true;
static int currentTime = 0;



int main(){
	if (fileParser(fileQueue)){
		while (!fileQueue.isEmpty()){
			arrive();
		}
		while (!bankQueue.isEmpty()){
			depart();
		}
	}
	output(EventQueue);
	return 0;
}
bool fileParser(PriorityQueue<Customer> &fileQueue){
	std::string filename = "file.txt";
	std::cout << "What's the file name? ";
	std::cin >> filename;

	std::ifstream file(filename);
	if (file.is_open()){
		int arrivalTime, waitingTime;
		while (file >> arrivalTime >> waitingTime){
			Customer customer(arrivalTime, waitingTime);
			fileQueue.enqueue(customer);
		}
		file.close();
		return true;
	}
	file.close();
	return false;

}

bool depart(){
		if(!bankQueue.isEmpty()){
			Customer customer = bankQueue.peekFront(); // sets the front of the bank q to customer
			if ( currentTime < customer.getArrivalTime() ) currentTime = customer.getArrivalTime();
			currentTime += customer.getWaitingTime(); // calcs departure time 
			EventQueue.enqueue(Event(currentTime, "departure")); // creates a newEvent for each customers type
			bankQueue.dequeue();
			return true;
		}
	return false;
}
bool arrive(){
	if (isTellerAvailable){
		currentTime = fileQueue.peekFront().getArrivalTime(); // sets the current time to arrival time of customer
		EventQueue.enqueue(Event(currentTime, "arrival"));
		currentTime += fileQueue.peekFront().getWaitingTime(); // sets the current time to actual departureTime
		EventQueue.enqueue(Event(currentTime, "departure")); // creates a newEvent for each customers type
		fileQueue.dequeue(); // takes off the customer off the queue
		isTellerAvailable = false;
		return true;
	}
	if (!fileQueue.isEmpty()){
		bankQueue.enqueue(fileQueue.peekFront()); // assuming that the event has a proper arrival time etc
		int arrivalTime = fileQueue.peekFront().getArrivalTime();
		EventQueue.enqueue(Event(arrivalTime, "arrival"));
		fileQueue.dequeue(); // takes off the customer off the queue
		return true;
	}
	return false;
}


void output(PriorityQueue<Event> EventQueue){
	while (!EventQueue.isEmpty()){
		std::string eventType = EventQueue.peekFront().getType();
		int time = EventQueue.peekFront().getTime();
		std::cout << "Processing " << eventType << " at time: " << time << std::endl;
		EventQueue.dequeue();
	}
}
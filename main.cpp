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

using namespace std;

#include "Customer.h"
#include "ArrayQueue.h"
#include "PriorityQueue.h"

bool fileParser(string filename, priorityQueue<Customer> &line);


int main(){

	
	return 1;
}
bool fileParser(){

}
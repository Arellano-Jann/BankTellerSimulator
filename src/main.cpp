/**
 * @file main.cpp
 * @author Jann Arellano and Jenavieve Layosa
 * @team_name team7
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
#include "helper.cpp"

int main(){
	if (fileParser()){
		while (!fileQueue.isEmpty()){
			arrive();
		}
		while (!bankQueue.isEmpty()){
			depart();
		}
	}
	output(EventQueue);
	output();
	return 0;
}
#pragma once
#define PRIORITYQUEUE_H

#include "QueueInterface.h"
#include "ArrayQueue.h"

template<typename T>
class PriorityQueue : public QueueInterface<T>{
private:
	/* data */
public:
	PriorityQueue(/* args */);
	~PriorityQueue();
};



#include "PriorityQueue.cpp"
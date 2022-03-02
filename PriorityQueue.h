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
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() const override;
	~PriorityQueue();
};



#include "PriorityQueue.cpp"
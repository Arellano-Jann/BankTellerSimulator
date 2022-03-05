#pragma once
#define PRIORITYQUEUE_H

#include "QueueInterface.h"
#include "ArrayQueue.h"

template<typename T>
class PriorityQueue : public QueueInterface<T>{
private:
	int front;
	int back;
	int numItems;
	static const int capacity = 50;
	T items[capacity];
public:
	PriorityQueue();
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() const override;
	~PriorityQueue();
};



#include "PriorityQueue.cpp"
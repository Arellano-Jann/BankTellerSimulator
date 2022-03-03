#pragma once
#define PRIORITYQUEUE_H

#include "QueueInterface.h"
#include "ArrayQueue.h"

template<typename T>
class PriorityQueue : public QueueInterface<T>{
private:
	int front = -1;
	int back = -1;
	int capacity;
	T items[capacity];
public:
	PriorityQueue();
	PriorityQueue(int capacity);
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() const override;
	~PriorityQueue();
};



#include "PriorityQueue.cpp"
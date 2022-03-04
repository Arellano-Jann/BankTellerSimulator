#pragma once
#define PRIORITYQUEUE_H

#include "QueueInterface.h"
#include "ArrayQueue.h"

template<typename T>
class PriorityQueue : public QueueInterface<T>{
private:
<<<<<<< HEAD:headers/PriorityQueue.h
	int front = -1;
	int back = -1;
=======
	int front;
	int back;
	int numItems;
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4:PriorityQueue.h
	static const int capacity = 10;
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



#include "../src/PriorityQueue.cpp"
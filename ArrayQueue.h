#pragma once
#define ARRAYQUEUE_H

#include "QueueInterface.h"

template<typename T>
class ArrayQueue : public QueueInterface<T>{
private:
	int front = 0;
	int back = 0;
	int itemCount = 0;
	int capacity = 50;
	T items[capacity]; // rememeber that it is a circular array
public:
	ArrayQueue(/* args */);
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() override;
	~ArrayQueue();
};

#include "ArrayQueue.cpp"
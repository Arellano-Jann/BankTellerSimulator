#pragma once
#define ARRAYQUEUE_H

#include "QueueInterface.h"

template<typename T>
class ArrayQueue : public QueueInterface<T>{
private:
	int front;
	int back;
	int numItems;
	static const int capacity = 50;
	T items[capacity]; // rememeber that it is a circular array
public:
	ArrayQueue();
	// ArrayQueue(int capacity);
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() const override;
	~ArrayQueue();
};

#include "../src/ArrayQueue.cpp"
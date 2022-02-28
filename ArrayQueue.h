#pragma once
#define ARRAYQUEUE_H

#include "QueueInterface.h"

template<typename T>
class ArrayQueue : public QueueInterface<T>{
private:
	int front = 0;
	int array[]; // rememeber that it is a circular array
public:
	ArrayQueue(/* args */);
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() override;
	~ArrayQueue();
};

#include "ArrayQueue.cpp"
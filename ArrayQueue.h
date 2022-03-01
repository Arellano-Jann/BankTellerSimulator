#pragma once
#define ARRAYQUEUE_H

#include "QueueInterface.h"

template<typename T>
class ArrayQueue : public QueueInterface<T>{
private:
	int frontIndex = -1;
	int backIndex = -1;
	int capacity;
	T items[capacity]; // rememeber that it is a circular array
public:
	ArrayQueue(int capacity);
	bool isEmpty() const override;
	bool enqueue(const T& newEntry) override;
	bool dequeue() override;
	T peekFront() const override;
	~ArrayQueue();
};

#include "ArrayQueue.cpp"
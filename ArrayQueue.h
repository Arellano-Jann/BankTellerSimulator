#pragma once
#define ARRAYQUEUE_H

#include "QueueInterface.h"

template<typename T>
class ArrayQueue : public QueueInterface<T>{
private:
	/* data */
public:
	ArrayQueue(/* args */);
	~ArrayQueue();
};

#include "ArrayQueue.cpp"
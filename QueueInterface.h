#pragma once
#define QUEUEINTERFACE_H

template<typename T>
class QueueInterface{

public:
	virtual bool isEmpty() const = 0;
	virtual bool enqueue(const T& newEntry) = 0;
	virtual bool dequeue() = 0;
	virtual T peekFront() = 0;
	~QueueInterface(){}
};

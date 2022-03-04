// template<typename T>
// ArrayQueue::ArrayQueue(int capacity)
//     : capacity(capacity)
//     {}

template<typename T>
ArrayQueue<T>::ArrayQueue()
    // : capacity(10)
<<<<<<< HEAD:src/ArrayQueue.cpp
    : front(-1)
    , back(-1)
=======
    : front(0)
    , back(0)
    , numItems(0)
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4:ArrayQueue.cpp
    {}

template<typename T>
ArrayQueue<T>::~ArrayQueue(){ while ( dequeue() ){} }

template<typename T>
bool ArrayQueue<T>::isEmpty() const{
<<<<<<< HEAD:src/ArrayQueue.cpp
    return front == -1;
=======
    return numItems == 0;
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4:ArrayQueue.cpp
}

template<typename T>
bool ArrayQueue<T>::enqueue(const T& newEntry){
    if (isEmpty()){
        items[back] = newEntry; // sets both front and back to be the same element
        numItems++;
        return true;
    }
    back++;
    back %= capacity; // index of back
    items[back] = newEntry;
    numItems++;
    return true;
}

template<typename T>
bool ArrayQueue<T>::dequeue(){
    if (isEmpty()){ return false; }
    front = (front + 1) % capacity; // index of front
    numItems--;
    return true;

}

template<typename T>
T ArrayQueue<T>::peekFront() const{
    return items[front];
}
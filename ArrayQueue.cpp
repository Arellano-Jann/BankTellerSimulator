template<typename T>
ArrayQueue::ArrayQueue(int capacity)
    : capacity(capacity)
    {}

template<typename T>
ArrayQueue::ArrayQueue()
    : capacity(10)
    {}

template<typename T>
ArrayQueue::~ArrayQueue(){ while ( dequeue() ) }

template<typename T>
bool ArrayQueue::isEmpty() const{
    return front == -1;
}

template<typename T>
bool ArrayQueue::enqueue(const T& newEntry){
    if (isEmpty()){
        front++;
        back++;
        items[back] = newEntry; // sets both front and back to be the same element
        return true;
    }
    else if (front == back){ // then it's the first element
        back++;
        front %= capacity; // index of front
        back %= capacity; // index of back
        items[back] = newEntry;
        return true;
    }
    // is there any checks that i'm missing??? i feel like there are
    return false;
}

template<typename T>
bool ArrayQueue::dequeue(){

}

template<typename T>
T ArrayQueue::peekFront() const{
    return items[front];
}
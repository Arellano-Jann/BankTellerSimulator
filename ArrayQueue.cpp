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
bool PriorityQueue::isEmpty() const{
    return front == -1;
}

template<typename T>
bool PriorityQueue::enqueue(const T& newEntry){
    if (isEmpty()){
        front++;
        back++;
        items[back] = newEntry; // sets both front and back to be the same element
    }
    else if (front == back){ // then it's the first element

    }
}

template<typename T>
bool PriorityQueue::dequeue(){

}

template<typename T>
T PriorityQueue::peekFront() const{
    return items[front];
}
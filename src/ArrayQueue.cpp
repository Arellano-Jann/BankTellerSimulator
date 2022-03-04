// template<typename T>
// ArrayQueue::ArrayQueue(int capacity)
//     : capacity(capacity)
//     {}

template<typename T>
ArrayQueue<T>::ArrayQueue()
    // : capacity(10)
    : front(-1)
    , back(-1)
    {}

template<typename T>
ArrayQueue<T>::~ArrayQueue(){ while ( dequeue() ){} }

template<typename T>
bool ArrayQueue<T>::isEmpty() const{
    return front == -1;
}

template<typename T>
bool ArrayQueue<T>::enqueue(const T& newEntry){
    if (isEmpty()){
        front++;
        back++;
        items[back] = newEntry; // sets both front and back to be the same element
        return true;
    }
    else{
        back++;
        back %= capacity; // index of back
        items[back] = newEntry;
        return true;
    }
    // is there any checks that i'm missing??? i feel like there are
    return false;
}

template<typename T>
bool ArrayQueue<T>::dequeue(){
    if (isEmpty()){ return false; }
    front = (front + 1) % capacity; // index of front
    return true;

}

template<typename T>
T ArrayQueue<T>::peekFront() const{
    return items[front];
}
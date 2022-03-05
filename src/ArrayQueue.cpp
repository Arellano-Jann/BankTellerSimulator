template<typename T>
ArrayQueue<T>::ArrayQueue()
    : front(0)
    , back(0)
    , numItems(0)
    {}

template<typename T>
ArrayQueue<T>::~ArrayQueue(){ while ( dequeue() ){} }

template<typename T>
bool ArrayQueue<T>::isEmpty() const{
    return numItems == 0;
}

template<typename T>
bool ArrayQueue<T>::enqueue(const T& newEntry){
    if (isEmpty()){
        items[back] = newEntry; // sets both front and back to be the same element
        numItems++;
        return true;
    }
    if (numItems < capacity){
        back++;
        back %= capacity; // index of back
        items[back] = newEntry;
        numItems++;
    }
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
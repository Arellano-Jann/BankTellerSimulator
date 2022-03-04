// template<typename T>
// PriorityQueue<T>::PriorityQueue(int capacity)
//     : capacity(capacity)
//     {}

template<typename T>
PriorityQueue<T>::PriorityQueue()
    // : capacity(10)
    {}

template<typename T>
PriorityQueue<T>::~PriorityQueue(){ while ( dequeue() ){} }

template<typename T>
bool PriorityQueue<T>::isEmpty() const{
    return front == -1;
}

template<typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry){
    if (isEmpty()){
        front++;
        back++;
        items[back] = newEntry; // sets both front and back to be the same element
        return true;
    }
    else{
        back++;
        back %= capacity; // index of back
        for (int i = back-1; i >= 0; i--){
            items[i+1] = items[i];
            if (items[i] < newEntry){ // if 6 is more than 5, then place 6 above 5
            // if lower prio vs higher prio, place lower prio below higher prio
            // left is lower prio. right is higher prio
                items[i+1] = newEntry;
                return true;
            }
        }
        return false; // see if it returns bad or something
    }
    return false;
}

template<typename T>
bool PriorityQueue<T>::dequeue(){
    if (isEmpty()){ return false; }
    front = (front + 1) % capacity; // index of front
    return true;

}

template<typename T>
T PriorityQueue<T>::peekFront() const{
    return items[front];
}
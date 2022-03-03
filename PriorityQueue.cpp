template<typename T>
PriorityQueue::PriorityQueue(int capacity)
    : capacity(capacity)
    {}

template<typename T>
PriorityQueue::PriorityQueue()
    : capacity(10)
    {}

template<typename T>
PriorityQueue::~PriorityQueue(){ while ( dequeue() ) }

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
        return true;
    }
    else{
        back++;
        back %= capacity; // index of back
        for (int i = back-1; i >= 0; i--){
            items[i+1] = items[i];
            if (items[i] < newEntry){
                items[i+1] = newEntry;
                return true;
            }
        }
        return false; // see if it returns bad or something
    }
    return false;
}

template<typename T>
bool PriorityQueue::dequeue(){
    if (isEmpty()){ return false; }
    front = (front + 1) % capacity; // index of front
    return true;

}

template<typename T>
T PriorityQueue::peekFront() const{
    return items[front];
}
template<typename T>
ArrayQueue::ArrayQueue(int capacity)
    : capacity(capacity)
    {}

template<typename T>
ArrayQueue::~ArrayQueue(){ while ( dequeue() ) }

template<typename T>
bool PriorityQueue::isEmpty() const{

}

template<typename T>
bool PriorityQueue::enqueue(const T& newEntry){

}

template<typename T>
bool PriorityQueue::dequeue(){

}

template<typename T>
T PriorityQueue::peekFront(){

}
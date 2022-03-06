PriorityQueue<Customer> fileQueue;
ArrayQueue<Customer> bankQueue;
PriorityQueue<Event> EventQueue;
bool isTellerAvailable = true;
static int currentTime = 0;
static int customerCount = 0;
static float totalWaitingTime = 0;

bool fileParser(){
	std::string filename = "file.txt";
	std::cout << "What's the file name? ";
	std::cin >> filename;

	std::ifstream file(filename);
	if (file.is_open()){
		int arrivalTime, waitingTime;
		while (file >> arrivalTime >> waitingTime){
			Customer customer(arrivalTime, waitingTime);
			fileQueue.enqueue(customer);
		}
		file.close();
		return true;
	}
	file.close();
	return false;

}

bool depart(){
		if(!bankQueue.isEmpty()){
			Customer customer = bankQueue.peekFront(); // sets the front of the bank q to customer
			if ( currentTime < customer.getArrivalTime() ) currentTime = customer.getArrivalTime();
			currentTime += customer.getWaitingTime(); // calcs departure time 
			totalWaitingTime += (currentTime - customer.getArrivalTime());
			EventQueue.enqueue(Event(currentTime, "departure")); // creates a newEvent for each customers type
			bankQueue.dequeue();
			return true;
		}
	return false;
}
bool arrive(){
	if (isTellerAvailable){
		currentTime = fileQueue.peekFront().getArrivalTime(); // sets the current time to arrival time of customer
		EventQueue.enqueue(Event(currentTime, "arrival"));
		currentTime += fileQueue.peekFront().getWaitingTime(); // sets the current time to actual departureTime
		totalWaitingTime += (currentTime - fileQueue.peekFront().getArrivalTime());
		EventQueue.enqueue(Event(currentTime, "departure")); // creates a newEvent for each customers type
		fileQueue.dequeue(); // takes off the customer off the queue
		isTellerAvailable = false;
		customerCount++;
		return true;
	}
	if (!fileQueue.isEmpty()){
		bankQueue.enqueue(fileQueue.peekFront()); // assuming that the event has a proper arrival time etc
		int arrivalTime = fileQueue.peekFront().getArrivalTime();
		EventQueue.enqueue(Event(arrivalTime, "arrival"));
		fileQueue.dequeue(); // takes off the customer off the queue
		customerCount++;
		return true;
	}
	return false;
}


void output(PriorityQueue<Event> EventQueue){
	while (!EventQueue.isEmpty()){
		std::string eventType = EventQueue.peekFront().getType();
		int time = EventQueue.peekFront().getTime();
		std::cout << "Processing " << eventType << " at time: " << time << std::endl;
		EventQueue.dequeue();
	}
}

void output(){
	std::cout << "Number of customers: " << customerCount << std::endl;
	std::cout << "Avg Waiting time: " << totalWaitingTime/customerCount << std::endl;
}
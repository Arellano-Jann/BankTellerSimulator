
class Event{
    std::string eventType;
    int time;

public:
    Event(std::string eventType, int time);
	bool operator <(Event rhs);

};
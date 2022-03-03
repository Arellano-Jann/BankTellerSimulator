

bool Event::operator <(Event rhs){
	return time < rhs.time; // doesn't work well. needs to account for customers departure time too
}

Event::Event(std::string eventType, int time)
    : eventType(eventType)
    , time(time)
{}
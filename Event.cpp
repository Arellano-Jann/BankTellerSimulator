

bool Customer::operator <(Customer rhs){
	return arrivalTime < rhs.arrivalTime; // doesn't work well. needs to account for customers departure time too
}
#include "Events.h"

Event& Events::operator+= (void(*func)()){
	_events.push_back(func);
	return _events.back();
}
Event& Events::operator+=(Event& ev){
	_events.push_back(ev);
	return ev;
}
Event& Events::operator[](std::size_t idx) {
	return _events[idx];
}
const Event& Events::operator[](std::size_t idx) const {
	return _events[idx];
}

int Events::size(){
	return _events.size();
}

void Events::fireEvents(){
	for (int i = 0; i < size(); i++){
		_events[i].fire();
		if (!_events[i].persistent()){
			_events.erase(_events.begin() + i);
			i--;
		}
	}
}
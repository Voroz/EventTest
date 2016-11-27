#include "Event.h"


Event::Event(void(*func)(), bool persistent) :
	funcPtr(func),
	_persistent(persistent) {

}

Event::~Event(){

}

void Event::fire(){
	funcPtr();
}

bool Event::persistent(){
	return _persistent;
}
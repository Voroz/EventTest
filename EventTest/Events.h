#pragma once
#include "Event.h"
#include <vector>

class Events{

public:

	Event& operator+=(void(*func)());
	Event& operator+=(Event& ev);
	Event& operator[](std::size_t idx);
	const Event& operator[](std::size_t idx) const;

	int size();
	void fireEvents();

private:
	std::vector<Event> _events;
};


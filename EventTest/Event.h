#pragma once

class Event{

public:
	Event(void(*func)(), bool persistent = true);
	~Event();

	void fire();
	bool persistent();

private:
	void(*funcPtr)();
	bool _persistent;
};


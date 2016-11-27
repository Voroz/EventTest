#include <iostream>
#include <vector>

using namespace std;

class Event{

public:
	Event(void(*func)()) :
		funcPtr(func){

	}
	void fire(){
		funcPtr();
	}

private:
	void(*funcPtr)();
};

class Events{

public:

	Events() :
		_size(0){
	
	}

	Event& operator+=(void(*func)()){
		_events.push_back(func);
		_size++;
		return _events.back();
	}
	Event& operator[](std::size_t idx) {
		return _events[idx];
	}
	const Event& operator[](std::size_t idx) const {
		return _events[idx];
	}

	int size(){
		return _size;
	}

private:
	int _size;
	vector<Event> _events;
};

class Button{
public:
	Events ClickEvent;

	void click(){
		for (int i = 0; i < ClickEvent.size(); i++){
			ClickEvent[i].fire();
		}
	}

};

void buttonEventFunc(){
	cout << "Button Event working!" << endl;
}
void buttonEventFunc2(){
	cout << "Button Event working 2!" << endl;
}

int main(){

	Button button;
	
	button.ClickEvent += buttonEventFunc;
	button.ClickEvent += buttonEventFunc2;

	button.click();

	while (1){

	}

	return 0;
}
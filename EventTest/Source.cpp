#include <iostream>
#include <vector>
#include "Events.h"

using namespace std;



class Button{
public:
	Events ClickEvent;

	void click(){
		ClickEvent.fireEvents();
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
	
	button.ClickEvent += Event(buttonEventFunc, false);
	button.ClickEvent += buttonEventFunc2;

	button.click();
	button.click();

	while (1){

	}

	return 0;
}
#pragma once

#include <vector>
#include "IInputObserver.h"

class InputHandler
{
private:
	std::vector<IInputObserver*> input_observers;
public:
	InputHandler() 
	{
		this->input_observers = std::vector<IInputObserver*>();
	}
	void register_input_observer(IInputObserver* observer);
	void unregister_input_observer(IInputObserver* observer);
	void notify_input_observers(sf::Event event);
};


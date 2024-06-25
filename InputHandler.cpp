#include "InputHandler.h"
#include <iostream>

void InputHandler::register_input_observer(IInputObserver *observer)
{

	input_observers.push_back(observer);
	for (auto obs : input_observers)
		std::cout << typeid(obs).name() << ", ";
}

void InputHandler::unregister_input_observer(IInputObserver* observer)
{
	auto found = std::find(input_observers.begin(), input_observers.end(), observer); 
	if (found != input_observers.end()) {
		input_observers.erase(found, found);
	}
	input_observers.erase(std::remove(input_observers.begin(), input_observers.end(), observer), input_observers.end());
}

void InputHandler::notify_input_observers(sf::Event event)
{
	for (IInputObserver* obs : input_observers) {
		obs->update(event);
	}
}

#pragma once
#include <SFML/Window/Event.hpp>

class IInputObserver
{
private:
public:
	virtual void update(sf::Event event) = 0;
};

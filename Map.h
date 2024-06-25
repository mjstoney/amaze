#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Map : public sf::Drawable
{
private:
public:
	Map() {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


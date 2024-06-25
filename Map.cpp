#include "Map.h"

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < X_TILES * Y_TILES; i++) {
		auto rect = sf::RectangleShape(sf::Vector2f(float(TILE_WIDTH), float(TILE_HEIGHT)));
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(1.0f);
		rect.setPosition(float(TILE_WIDTH * (i % X_TILES)), float(TILE_HEIGHT * (i / X_TILES)));
		target.draw(rect);
	}
}

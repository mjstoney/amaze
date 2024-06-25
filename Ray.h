#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "IInputObserver.h"
#include "Definitions.h"

class Ray : public sf::Drawable, public IInputObserver
{

public:
	float length, angle, move_speed, angular_speed;
	sf::Vector2f pos;
	sf::Vector2f dir;
	Ray() : pos({ 0.0f, 0.0f }), angle(0), move_speed(0), angular_speed(0), length(RAY_LENGTH) {}
	Ray(sf::Vector2f pos, sf::Vector2f dir) : pos(pos), dir(dir), angle(0), move_speed(0), angular_speed(0), length(RAY_LENGTH) {}
	Ray(float x_pos, float y_pos, float x_dir, float y_dir, float length) : pos({ x_pos, y_pos }), angle(0), dir({ x_dir, y_dir }), move_speed(0), angular_speed(0), length(length) {}

	// Inherited via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();

	// Inherited via IInputObserver
	void update(sf::Event event) override;

	void rotate();
	void translate();
};


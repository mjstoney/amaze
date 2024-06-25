#pragma once
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include "Ray.h"
#include "IInputObserver.h"
#include "InputHandler.h"

class Camera : public sf::Drawable, public IInputObserver
{
private:
	int x_pos;
	int y_pos;
	float move_speed, angular_speed, angle;
	sf::CircleShape marker;
	std::shared_ptr<Ray> pointer;
	std::shared_ptr<InputHandler> inputHandler;

public:
	//Camera() : x_pos(0), y_pos(0) {}
	Camera() : x_pos(WIDTH / 2), y_pos(HEIGHT / 2), move_speed(0.0f), angular_speed(0.0f), angle(0.0f) {}
	Camera(int x, int y, std::shared_ptr<InputHandler> inputHandler) : x_pos(x), y_pos(y), move_speed(0.0f), angular_speed(0.0f), angle(0.0f), inputHandler(inputHandler) {}
	void init();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();

	// Inherited via IInputObserver
	void update(sf::Event event) override;
	void translate();
	void rotate();
};


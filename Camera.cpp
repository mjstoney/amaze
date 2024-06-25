#include "Camera.h"
#include <iostream>

void Camera::init()
{
	this->marker = sf::CircleShape(10.0f);
	this->marker.setPosition(float(x_pos), float(y_pos));
	std::cout << x_pos << ", " << y_pos << std::endl;
	std::cout << this->marker.getPosition().x << ", " << this->marker.getPosition().y << std::endl;

	this->marker.setFillColor(sf::Color::Black);
	this->marker.setOrigin(10.0f, 10.0f);

	this->pointer = std::make_shared<Ray>(this->x_pos, this->y_pos, this->x_pos + 20.0f, this->y_pos + 20.0f, 50.0f);
	this->inputHandler->register_input_observer(this);
	//this->inputHandler->register_input_observer(pointer.get());
}


void Camera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->marker);
	this->pointer->draw(target, states);
}

void Camera::update()
{
	translate();
	rotate();
}

void Camera::update(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{

		if (event.key.code == sf::Keyboard::W) {
			move_speed = CAMERA_SPEED;
		}
		if (event.key.code == sf::Keyboard::S) {
			move_speed = -CAMERA_SPEED;
		}
		if (event.key.code == sf::Keyboard::A) {
			angular_speed = -CAMERA_ANGULAR_SPEED;
		}
		if (event.key.code == sf::Keyboard::D) {
			angular_speed = CAMERA_ANGULAR_SPEED;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W) {
			move_speed = 0;
		}
		if (event.key.code == sf::Keyboard::S) {
			move_speed = 0;
		}
		if (event.key.code == sf::Keyboard::A) {
			angular_speed = 0;
		}
		if (event.key.code == sf::Keyboard::D) {
			angular_speed = 0;
		}
	}
}



void Camera::translate() 
{
	float rads = angle * 3.14159f / 180.0f;

	x_pos = x_pos + move_speed * cos(rads);
	y_pos = y_pos + move_speed * sin(rads);
	this->marker.setPosition(float(x_pos), float(y_pos));

	this->pointer->pos.x = x_pos + move_speed * cos(rads);
	this->pointer->pos.y = y_pos + move_speed * sin(rads);
	this->pointer->dir.x = this->pointer->pos.x + this->pointer->length * cos(rads);
	this->pointer->dir.y = this->pointer->pos.y + this->pointer->length * sin(rads);

}

void Camera::rotate() 
{
	angle += angular_speed;
}
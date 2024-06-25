#include "Ray.h"


void Ray::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::VertexArray ray(sf::Lines);
	ray.append(sf::Vertex(this->pos, sf::Color::Black));
	ray.append(sf::Vertex(this->dir, sf::Color::Black));
	target.draw(ray);
}


void Ray::update(sf::Event event)
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



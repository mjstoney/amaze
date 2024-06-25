#include "Window.h"
#include <iostream>

void Window::init()
{
	this->mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(this->width, this->height), this->title, sf::Style::Default);
	//this->mWindow->setVerticalSyncEnabled(true);
	this->mWindow->setFramerateLimit(60);
	this->inputHandler = std::make_shared<InputHandler>();

	this->map = std::make_unique<Map>();
	this->camera = std::make_unique<Camera>(400.0f, 300.0f, inputHandler);
	this->camera->init();
	//this->inputHandler->register_input_observer(this->camera.get());
}

void Window::run()
{
	while(this->mWindow->isOpen()) {
		sf::Event event;
		while (this->mWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				this->mWindow->close();
			}
			//if (event.type == sf::Event::KeyPressed) {

			this->inputHandler->notify_input_observers(event);
			//}
		}
		this->mWindow->clear();
		this->update();
		this->draw();
		this->mWindow->display();
	}
}

void Window::update()
{
	this->camera->update();
}

void Window::draw()
{
	this->map->draw(*mWindow, sf::RenderStates::Default);
	this->camera->draw(*mWindow, sf::RenderStates::Default);
}

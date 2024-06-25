#pragma once
#include <SFML/Window.hpp>
#include <memory>
#include "Map.h"
#include "Definitions.h"
#include "Camera.h"
#include "InputHandler.h"

class Window
{
private:
	std::unique_ptr<sf::RenderWindow> mWindow;
	std::unique_ptr<Map> map;
	std::unique_ptr<Camera> camera;
	std::shared_ptr<InputHandler> inputHandler;
	int width;
	int height;
	std::string title;
public:
	Window() : width(WIDTH), height(HEIGHT), title(TITLE) {}
	Window(int width, int height, std::string title) : width(width), height(height), title(title) {}
	
	void init();
	void run();
	void update();
	void draw();

};


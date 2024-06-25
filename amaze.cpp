#include <iostream>
#include "Window.h"

int main()
{
	Window window = Window(800, 600, "Demo");
	window.init();
	window.run();

}


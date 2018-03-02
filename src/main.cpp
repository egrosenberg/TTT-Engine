#include "main.h"

int main()
{
	Display *window;
	Controller *input;
	window = new Display();
	input = new Controller();
	
	bool running = true;
	
	while (running)
	{
		input->Update();
		window->Update();
	}
	
}

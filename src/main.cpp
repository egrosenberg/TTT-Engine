#include "main.h"

Display*  e_Display = new Display();

int main()
{
	//Display *window;
	Controller *input;
	//window = new Display();
	input = new Controller();
	
	bool running = true;
	
	while (running)
	{
		input->Update();
		running = e_Display->Update();
	}
	
}

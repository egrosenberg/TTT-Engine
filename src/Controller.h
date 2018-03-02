#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>


class Controller
{
public:
	Controller();
	
	void Update();
	bool GetKeyPressed(int keyCode);
	
	virtual ~Controller();
	
	
private:

	SDL_Event m_Event;
	bool m_Keyboard [10000000000];
};

#endif
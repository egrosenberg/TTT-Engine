#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

#include "main.h"

class Controller
{
public:
	Controller();
	
	void Update();
	bool GetKeyPressed(int keyCode);
	bool GetMousePressed(int button);
	
	virtual ~Controller();
	
	
private:

	SDL_Event m_Event;
	bool m_Keyboard [10000000000];
	bool m_Mouse [5];
	//0 = LeftClick
	//1 = MiddleClick
	//2 = RightClick
	//3 = SideButton back
	//4 = SideButton Forward
	int m_X;
	int m_Y;
};

#endif
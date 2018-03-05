#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "main.h"


class Button
{
public:
	Button();
	
	void SetColor(SDL_Surface* surface, int r, int g, int b);
	
	virtual ~Button();
private:
	SDL_Rect m_Rect;
	Uint32 m_Color;
};


#endif
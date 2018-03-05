#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <cstdlib>

#include "main.h"

class Display
{
private:
	int m_WinX;
	int m_WinY;
	
	SDL_Rect m_Rect;
	SDL_Rect m_PastRect [500];
	SDL_Rect m_Fruit;
	
	SDL_Rect m_BGRect;
	Uint32 m_BGcolor;
	Uint32 m_FruitColor;
	
	SDL_Window* m_Window;
	SDL_Surface* m_Surface;
	
	int m_Direction;
	//0 = south, 1 = north, 2 = east, 3 = west
	int m_Length;

public:
	Display();
	
	
	bool Update();
	SDL_Window* GetWindow()
	{
		return m_Window;
	}
	SDL_Surface* GetSurface()
	{
		return m_Surface;
	}	
	void DrawRect(int posX, int posY, int width, int height, Uint32 color);
	
	virtual ~Display();
	
};

#endif
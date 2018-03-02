#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include "Controller.h"



class Display
{
private:
	int m_WinX;
	int m_WinY;
	
	SDL_Rect m_Rect;
	SDL_Rect m_PastRect;
	
	SDL_Rect m_BGRect;
	Uint32 m_BGcolor;
	
	SDL_Window* m_Window;
	SDL_Surface* m_Surface;

public:
	Display();
	
	
	void Update();
	SDL_Window* getWindow()
	{
		return m_Window;
	}
	SDL_Surface* getsurface()
	{
		return m_Surface;
	}	
	
	virtual ~Display();
	
};

#endif

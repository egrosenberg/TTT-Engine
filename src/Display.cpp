#include "Display.h"

Display::Display()
{
	Uint32 start;
	m_WinX = 1300;
	m_WinY = 800;
	
	m_Rect.x = 300;
	m_Rect.y = 300;
	m_Rect.w = 30;
	m_Rect.h = 30;

	m_PastRect = m_Rect;
	
	m_BGRect.x = 0;
	m_BGRect.y = 0;
	m_BGRect.w = m_WinX;
	m_BGRect.h = m_WinY;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
	}
	m_Window = SDL_CreateWindow(
			   "Thomas the Tank",
			   0, 0,
			   m_WinX, m_WinY,
			   SDL_WINDOW_SHOWN
			   );
	
	m_Surface = SDL_GetWindowSurface(m_Window);
	
	m_BGcolor = SDL_MapRGB(m_Surface->format,0x77,0x00,0x00);

}

void Display::Update()
{
	SDL_FillRect(m_Surface, &m_BGRect, m_BGcolor);
	
	Controller *tempInput;
	tempInput->Update();
	Uint32 tempColor = SDL_MapRGB(m_Surface->format,0xff,0xff,0xff);

	Uint32 black = SDL_MapRGB(m_Surface->format,0x00,0x00,0x00);
	int speed = 1;

	SDL_FillRect(m_Surface, &m_PastRect, tempColor);


	if(tempInput->GetKeyPressed(115) || tempInput->GetKeyPressed(1073741905))
	//115 = s
	//1073741905 = Downarrow
	{
		m_Rect.y += m_Rect.w;
	}
	else if(tempInput->GetKeyPressed(119) || tempInput->GetKeyPressed(1073741906))
	//119 = w
	//1073741906 = Uparrow
	{
		m_Rect.y -= m_Rect.w;
	}
	else if(tempInput->GetKeyPressed(100) || tempInput->GetKeyPressed(1073741903))
	//100 = d
	//1073741903 = Rightarrow
	{
		m_Rect.x += m_Rect.w;
	}
	else if(tempInput->GetKeyPressed(97) || tempInput->GetKeyPressed(1073741904))
	//97 = a
	//1073741904 = Leftarrow
	{
		m_Rect.x -= m_Rect.w;
	}
	SDL_FillRect(m_Surface, &m_Rect, tempColor);

	SDL_UpdateWindowSurface(m_Window);
	SDL_Delay(10);
	SDL_FillRect(m_Surface, NULL, 0x000000);
	m_PastRect = m_Rect;
}

Display::~Display()
{
	SDL_DestroyWindow(m_Window);
	SDL_Quit();	
}
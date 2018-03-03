#include "Display.h"

Display::Display()
{
	Uint32 start;
	m_WinX = 1300;
	m_WinY = 800;
	
	m_Rect.x = 300;
	m_Rect.y = 300;
	m_Rect.w = 15;
	m_Rect.h = 15;

	for (int n  = 0; n < m_Length; n++)
	{
		m_PastRect [n].x = m_Rect.x;// - (m_Rect.w * n);
		m_PastRect [n].y = m_Rect.y;
		m_PastRect [n].w = m_Rect.w;
		m_PastRect [n].h = m_Rect.h;
	}
	
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
	
	m_Direction = 2;
	m_Length = 0;

}

bool Display::Update()
{
	SDL_FillRect(m_Surface, &m_BGRect, m_BGcolor);
	
	Controller *tempInput;
	tempInput->Update();
	Uint32 tempColor = SDL_MapRGB(m_Surface->format,0xff,0xff,0xff);

	Uint32 black = SDL_MapRGB(m_Surface->format,0x00,0x00,0x00);
	int speed = 1;

	for (int n = 0; n < 10 ; n++)
	{
		SDL_FillRect(m_Surface, &m_PastRect [n] , tempColor);
	}


	if(tempInput->GetKeyPressed(115) || tempInput->GetKeyPressed(1073741905))
	//115 = s
	//1073741905 = Downarrow
	{
		if (m_Direction != 1)
		{
			m_Direction = 0;
		}
	}
	else if(tempInput->GetKeyPressed(119) || tempInput->GetKeyPressed(1073741906))
	//119 = w
	//1073741906 = Uparrow
	{
		if (m_Direction != 0)
		{		
			m_Direction = 1;
		}
	}
	else if(tempInput->GetKeyPressed(100) || tempInput->GetKeyPressed(1073741903))
	//100 = d
	//1073741903 = Rightarrow
	{
		if (m_Direction != 3)
		{
			m_Direction = 2;
		}
	}
	else if(tempInput->GetKeyPressed(97) || tempInput->GetKeyPressed(1073741904))
	//97 = a
	//1073741904 = Leftarrow
	{
		if (m_Direction != 2)
		{
			m_Direction = 3;
		}
	}
	
	switch(m_Direction)
	{
		case 0:
			m_Rect.y += m_Rect.w + 2;
			break;
		case 1:
			m_Rect.y -= m_Rect.w + 2;
			break;
		case 2:
			m_Rect.x += m_Rect.w + 2;
			break;
		case 3:
			m_Rect.x -= m_Rect.w + 2;
			break;
	}
	
	SDL_FillRect(m_Surface, &m_Rect, tempColor);

	SDL_UpdateWindowSurface(m_Window);
	SDL_Delay(50);
	SDL_FillRect(m_Surface, NULL, 0x000000);
	
	for (int n = m_Length - 1; n >= 0 ; n--)
	{
		if ((m_Rect.x == m_PastRect [n].x) && (m_Rect.y == m_PastRect [n].y))
		{
			return false;
		}
	}
	
	m_PastRect [0] = m_Rect;
	for (int n = m_Length - 1; n >= 0 ; n--)
	{
			m_PastRect[n] = m_PastRect[n-1];
	}
}

Display::~Display()
{
	SDL_DestroyWindow(m_Window);
	SDL_Quit();	
}
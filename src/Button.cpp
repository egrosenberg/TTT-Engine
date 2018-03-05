#include "Button.h"

Button::Button()
{
	m_Rect.x = 0;
	m_Rect.y = 0;
	m_Rect.w = 0;
	m_Rect.h = 0;
}

void Button::SetColor(SDL_Surface* surface, int r, int g, int b)
{
		m_Color = SDL_MapRGB(surface->format, r, g, b);
} 

Button::~Button()
{
}
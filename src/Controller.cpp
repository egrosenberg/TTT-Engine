#include "Controller.h"

Controller::Controller()
{
}

void Controller::Update()
{
	while(SDL_PollEvent (&m_Event))
	{
		switch(m_Event.type)
		{
			case SDL_KEYDOWN:
				m_Keyboard [m_Event.key.keysym.sym] = true;
				std::cout<< m_Event.key.keysym.sym << std::endl;
				break;
			case SDL_KEYUP:
				m_Keyboard [m_Event.key.keysym.sym] = false;
				std::cout<< m_Event.key.keysym.sym << " UP" <<std::endl;
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_Mouse [static_cast <int> (m_Event.button.button) - 1] = true;
				std::cout << static_cast <int> (m_Event.button.button) << std::endl;
				break;
			case SDL_MOUSEBUTTONUP:
				m_Mouse [static_cast <int> (m_Event.button.button) - 1] = false;
				std::cout << static_cast <int> (m_Event.button.button) << " UP" <<std::endl;
				break;
		}
	}
	SDL_GetMouseState(&m_X, &m_Y);
	std::cout<< m_X << " , " << m_Y << std::endl;
}

bool Controller::GetKeyPressed(int keyCode)
{
	if(m_Keyboard [keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Controller::GetMousePressed(int button)
{
	if (button > 4)
	{
		button = 4;
	}
	if (button < 0)
	{
		button = 0;
	}
	return m_Mouse [button];
}

Controller::~Controller()
{
	
}
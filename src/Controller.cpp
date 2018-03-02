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
		}
	}
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

Controller::~Controller()
{
	
}
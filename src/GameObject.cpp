#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

void GameObject::Update()
{
	xpos = 0;
	ypos = 0;
	
	// Get texture width and height
	int w, h;
	SDL_QueryTexture(objTexture, NULL, NULL, &w, &h);
	
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = w;
	srcRect.h = h;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 458/2;
	destRect.h = 436/2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
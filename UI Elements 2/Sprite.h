#pragma once
#include <string>
#include <SDL.h>

class Sprite
{
public:

	bool Load(const std::string& filename); //Load in the image from the given filepath

	void SetSpriteDimension(const SDL_Point& dimension); //setting the dimension of the image that is on screen
	void SetOriginalDimension();

	const SDL_Point& GetSpriteDimension(); //gets the image on screen dimension
	const SDL_Point& GetOriginalDimension();

	void Render(const SDL_Point& position, float angle = 0);
	void Unload(); //shutdown purposes

private:

	SDL_Texture* m_texture = nullptr;
	SDL_Point m_spriteDimension = { 0, 0 };
	SDL_Point m_originalDimension = { 0, 0 };
};
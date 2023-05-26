#include "Sprite.h"
#include "Screen.h"
#include <iostream>
#include <SDL_image.h>

bool Sprite::Load(const std::string& filename)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());

	if (!rawImageData)
	{
		std::cout << "Error loading image file." << std::endl;
		std::cout << filename;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), rawImageData);
	return true;
}

void Sprite::Render(const SDL_Point& position, float angle)
{
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = m_originalDimension.x;
	sourceRect.h = m_originalDimension.y;

	targetRect.x = position.x;
	targetRect.y = position.y;
	targetRect.w = m_spriteDimension.x;
	targetRect.h = m_spriteDimension.y;

	SDL_Point centre{ m_spriteDimension.x / 2, m_spriteDimension.y / 2 };

	SDL_RenderCopyEx(Screen::Instance()->GetRenderer(), m_texture, &sourceRect, &targetRect, angle, &centre, SDL_FLIP_NONE);
}

//How it will appear on screen
void Sprite::SetSpriteDimension(const SDL_Point& dimensions)
{
	m_spriteDimension = dimensions;
}

//Change: instead of manually setting, SDL_QueryTexture does it for you
void Sprite::SetOriginalDimension()
{
	SDL_QueryTexture(m_texture, NULL, NULL, &m_originalDimension.x, &m_originalDimension.y);
}

const SDL_Point& Sprite::GetSpriteDimension()
{
	return m_spriteDimension;
}

const SDL_Point& Sprite::GetOriginalDimension()
{
	return m_originalDimension;
}

void Sprite::Unload()
{
	SDL_DestroyTexture(m_texture);
}
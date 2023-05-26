#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include <SDL.h>

class Button : public GameObject
{
public:

	Button();
	~Button();

	enum class ButtonState
	{
		Default,
		Hovered,
		Clicked
	};

	void SetButtonRect(float rotationAngle = 0.0f);
	SDL_Point GetMousePosition();

	void SetNormalAttributes(const std::string& filename, const SDL_Point& spriteDimensions);
	void SetHoveredAttributes(const std::string& filename, const SDL_Point& spriteDimensions);

	virtual bool Update() override;
	virtual bool Render() override;

private:

	Sprite m_normalSprite;
	Sprite m_hoveredSprite;
	SDL_Rect m_buttonRect = { 0, 0, 0, 0 };
	SDL_Point m_mousePosition = { 0, 0 };
	ButtonState m_buttonState = { ButtonState::Default };
};
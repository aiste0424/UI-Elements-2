#pragma once
#include "Sprite.h"
#include "GameObject.h"

#include <SDL.h>

class ModalWindow : public GameObject
{
public:

	ModalWindow();
	~ModalWindow();

	void SetBackgroundAttributes(const std::string& filename, const SDL_Point& spriteDimensions);
	void SetButtonAttributes(const std::string& filename, const SDL_Point& spriteDimensions);
	void SetOpen();
	void SetClose();
	void HandleEvent(const SDL_Event& event);

	virtual bool Update() override { return false; }
	virtual bool Render() override;

private:

	Sprite m_backgroundSprite;
	Sprite m_closeButtonSprite;

	SDL_Rect m_windowRect = { 0, 0, 0, 0 };
	SDL_Rect m_closeButtonRect = { 0, 0, 0, 0 };

	bool m_isOpen = true;
};
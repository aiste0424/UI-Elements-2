#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Sprite.h"

class ToggleButton : public GameObject
{
public:

	ToggleButton();
	~ToggleButton();

	void SetOnAttributes(const std::string& filename, const SDL_Point& spriteDimensions);
	void SetOffAttributes(const std::string& filename, const SDL_Point& spriteDimensions);

	void SetState(bool state);
	bool GetToggleState() const;
	void HandleEvent(const SDL_Event& event);

	virtual bool Update() override { return false; }
	virtual bool Render() override;

private:

	Sprite m_onSprite;
	Sprite m_offSprite;

	SDL_Rect m_rect = { 0, 0, 0, 0 };
	bool m_state = false;
};
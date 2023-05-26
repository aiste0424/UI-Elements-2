#pragma once
#include "GameObject.h"
#include "Sprite.h"

class ProgressBar : public GameObject
{
public:

	ProgressBar();
	~ProgressBar();

	void SetBackgroundAttributes(const std::string& filename, const SDL_Point& spriteDimension);
	void SetFillAttributes(const std::string& filename, const SDL_Point& spriteDimension);
	void SetValue(int value);

	virtual bool Update() override;
	virtual bool Render() override;

private:

	Sprite m_backgroundSprite;
	Sprite m_fillSprite;
	SDL_Rect m_backgroundRect = { 0, 0, 0, 0 };
	SDL_Rect m_fillRect = { 0, 0, 0, 0 };

	int m_maxValue = 100;
	int m_currentValue = 0;
};
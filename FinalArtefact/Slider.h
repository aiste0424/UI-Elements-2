#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Screen.h"
#include "Input.h"

#include <string>

class Slider : public GameObject
{
public:

	Slider();
	~Slider();

	//setting up the slider background and slider attributes (sprite and position)
	void SetBackgroundAttributes(const std::string& filename, const SDL_Point& dimensions);
	void SetSliderAttributes(const std::string& filename, const SDL_Point& dimensions);

	void SetValue(int newValue);
	int GetValue() const;
	void HandleEvent(const SDL_Event& event);

	virtual bool Update() override;
	virtual bool Render() override;

private:

	Sprite m_backgroundSprite;
	Sprite m_sliderSprite;

	int m_minValue = 0;
	int m_maxValue = 100;
	int m_currentValue = 0;

	bool m_isDragging = false;
	int m_offset = 0;
	SDL_Point m_backgroundPosition = { 0, 0 };
	SDL_Point m_sliderPosition =  {0, 0 };
};
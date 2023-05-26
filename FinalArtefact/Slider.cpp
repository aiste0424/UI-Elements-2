#include "Slider.h"
#include <algorithm>
#include <iostream>

Slider::Slider()
{
    this->SetPosition({ 50, 50 });
    std::string defaultBackgroundSpriteFilename = "Assets/Slider/Slider_Background.png";
    std::string defaultSliderSpriteFilename = "Assets/Slider/Slider_Slider.png";

    SDL_Point defaultBackgroundSpriteDimension = { 328, 8 };
    SDL_Point defaultSliderSpriteDimension = { 48, 48 };

    auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
        const SDL_Point& spriteDimensions, SDL_Point& position)
    {
        sprite.Load(filename);
        sprite.SetOriginalDimension();
        sprite.SetSpriteDimension(spriteDimensions);
        position = this->GetPosition();
    };
    
    InitializingDefaults(m_backgroundSprite, defaultBackgroundSpriteFilename, defaultBackgroundSpriteDimension, m_backgroundPosition);
    InitializingDefaults(m_sliderSprite, defaultSliderSpriteFilename, defaultSliderSpriteDimension, m_sliderPosition);
    SetValue(0);
}

Slider::~Slider()
{
    m_backgroundSprite.Unload();
    m_sliderSprite.Unload();
}

void Slider::SetBackgroundAttributes(const std::string& filename, const SDL_Point& dimensions)
{
	m_backgroundSprite.Load(filename);
	m_backgroundSprite.SetOriginalDimension();
	m_backgroundSprite.SetSpriteDimension(dimensions);
	m_backgroundPosition = this->GetPosition();
}

void Slider::SetSliderAttributes(const std::string& filename, const SDL_Point& dimensions)
{
	m_sliderSprite.Load(filename);
	m_sliderSprite.SetOriginalDimension();
	m_sliderSprite.SetSpriteDimension(dimensions);
	m_sliderPosition = this->GetPosition();
	SetValue(0);
}

void Slider::SetValue(int newValue)
{
	m_currentValue = newValue;
	m_currentValue = std::clamp(m_currentValue, m_minValue, m_maxValue);

	// Update rendering positions
	int sliderRange = m_backgroundSprite.GetSpriteDimension().x - m_sliderSprite.GetSpriteDimension().x;
	m_sliderPosition.x = m_backgroundPosition.x + static_cast<int>((m_currentValue - m_minValue) / static_cast<double>(m_maxValue - m_minValue) * sliderRange);
	m_sliderPosition.y = m_backgroundPosition.y - m_sliderSprite.GetSpriteDimension().y/2.5;
}

int Slider::GetValue() const
{
	return m_currentValue;
}

void Slider::HandleEvent(const SDL_Event& event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            int mouseX = event.button.x;
            int mouseY = event.button.y;

            if (mouseX >= m_sliderPosition.x && mouseX <= m_sliderPosition.x + m_sliderSprite.GetSpriteDimension().x &&
                mouseY >= m_sliderPosition.y && mouseY <= m_sliderPosition.y + m_sliderSprite.GetSpriteDimension().y)
            {
                m_isDragging = true;
                m_offset = mouseX - m_sliderPosition.x;
            }
        }
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            m_isDragging = false;
        }
    }
    else if (event.type == SDL_MOUSEMOTION)
    {
        if (m_isDragging)
        {
            int mouseX = event.motion.x;
            int newValue = static_cast<int>((mouseX - m_offset - m_backgroundPosition.x) / static_cast<double>(m_backgroundSprite.GetSpriteDimension().x) * (m_maxValue - m_minValue) + m_minValue);
            SetValue(newValue);
        }
    }
}

bool Slider::Update()
{
	return false;
}

bool Slider::Render()
{
	m_backgroundSprite.Render(m_backgroundPosition);
	m_sliderSprite.Render(m_sliderPosition);
	return false;
}
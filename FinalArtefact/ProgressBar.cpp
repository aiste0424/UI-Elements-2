#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
    this->SetPosition({ 50, 50 });
    std::string defaultBackgroundSpriteFilename = "Assets/ProgressBar/ProgressBar_Background.png";
    std::string defaultFillSpriteFilename = "Assets/ProgressBar/ProgressBar_Fill.png";

    SDL_Point defaultBackgroundSpriteDimension = { 280, 8 };
    SDL_Point defaultFillSpriteDimension = { 280, 8 };

    auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
        const SDL_Point& spriteDimensions, SDL_Rect& rect)
    {
        sprite.Load(filename);
        sprite.SetOriginalDimension();
        sprite.SetSpriteDimension(spriteDimensions);
        rect = { this->GetPosition().x, this->GetPosition().y, sprite.GetSpriteDimension().x,
                    sprite.GetSpriteDimension().y };
    };

    InitializingDefaults(m_backgroundSprite, defaultBackgroundSpriteFilename, defaultBackgroundSpriteDimension, m_backgroundRect);
    InitializingDefaults(m_fillSprite, defaultFillSpriteFilename, defaultFillSpriteDimension, m_fillRect); 
}

ProgressBar::~ProgressBar()
{
    m_backgroundSprite.Unload();
    m_fillSprite.Unload();
}

void ProgressBar::SetBackgroundAttributes(const std::string& filename, const SDL_Point& spriteDimension)
{
    m_backgroundSprite.Load(filename);
    m_backgroundSprite.SetOriginalDimension();
    m_backgroundSprite.SetSpriteDimension(spriteDimension);
    m_backgroundRect = { this->GetPosition().x, this->GetPosition().y, m_backgroundSprite.GetSpriteDimension().x,
                        m_backgroundSprite.GetSpriteDimension().y };
}

void ProgressBar::SetFillAttributes(const std::string& filename, const SDL_Point& spriteDimension)
{
    m_fillSprite.Load(filename);
    m_fillSprite.SetOriginalDimension();
    m_fillSprite.SetSpriteDimension(spriteDimension);
    m_fillRect = { this->GetPosition().x, this->GetPosition().y, m_fillSprite.GetSpriteDimension().x,
                        m_fillSprite.GetSpriteDimension().y };
}

void ProgressBar::SetValue(int value)
{
    m_currentValue = value;
    m_currentValue = std::max(0, std::min(m_currentValue, m_maxValue));

    m_fillSprite.SetSpriteDimension({m_backgroundSprite.GetSpriteDimension().x * m_currentValue / m_maxValue, m_backgroundSprite.GetSpriteDimension().y});
}

bool ProgressBar::Update()
{
    return false;
}

bool ProgressBar::Render()
{
    m_backgroundSprite.Render(this->GetPosition());
    m_fillSprite.Render(this->GetPosition());
    return false;
}
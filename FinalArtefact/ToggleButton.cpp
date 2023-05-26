#include "ToggleButton.h"
#include "Input.h"

ToggleButton::ToggleButton()
{
    this->SetPosition({ 50, 50 });
    std::string defaultOnSpriteFilename = "Assets/ToggleButton/ToggleButton_On.png";
    std::string defaultOffSpriteFilename = "Assets/ToggleButton/ToggleButton_Off.png";

    SDL_Point defaultOnSpriteDimension = { 53, 32 };
    SDL_Point defaultOffSpriteDimension = { 53, 32 };

    auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
        const SDL_Point& spriteDimensions)
    {
        sprite.Load(filename);
        sprite.SetOriginalDimension();
        sprite.SetSpriteDimension(spriteDimensions);
        
    };

    InitializingDefaults(m_onSprite, defaultOnSpriteFilename, defaultOnSpriteDimension);
    InitializingDefaults(m_offSprite, defaultOffSpriteFilename, defaultOffSpriteDimension);

    m_rect = { this->GetPosition().x, this->GetPosition().y, m_onSprite.GetSpriteDimension().x,
                    m_onSprite.GetSpriteDimension().y };
}

ToggleButton::~ToggleButton()
{
    m_onSprite.Unload();
    m_offSprite.Unload();
}

void ToggleButton::SetOnAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
    m_onSprite.Load(filename);
    m_onSprite.SetOriginalDimension();
    m_onSprite.SetSpriteDimension(spriteDimensions);
    m_rect = { this->GetPosition().x, this->GetPosition().y, m_onSprite.GetSpriteDimension().x, m_onSprite.GetSpriteDimension().y };
}

void ToggleButton::SetOffAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
    m_offSprite.Load(filename);
    m_offSprite.SetOriginalDimension();
    m_offSprite.SetSpriteDimension(spriteDimensions);
}

void ToggleButton::SetState(bool state)
{
	m_state = state;
}

bool ToggleButton::GetToggleState() const
{
	return m_state;
}

void ToggleButton::HandleEvent(const SDL_Event& event)
{
    if (Input::Instance()->isLeftMouseButtonClicked())
    {
        int mouseX = event.button.x;
        int mouseY = event.button.y;

        if (mouseX >= m_rect.x && mouseX <= m_rect.x + m_rect.w &&
            mouseY >= m_rect.y && mouseY <= m_rect.y + m_rect.h)
        {
            m_state = !m_state;
        }
    }
}

bool ToggleButton::Render()
{
    if (m_state)
    {
        m_onSprite.Render(this->GetPosition());
    }
    else
    {
        m_offSprite.Render(this->GetPosition());
    }
	return false;
}

#include "Button.h"
#include "Input.h"
#include <iostream>

Button::Button()
{
    this->SetPosition({ 50, 50 });
    std::string defaultNormalSpriteFilename = "Assets/Button/Button_Normal.png";
    std::string defaultHoveredSpriteFilename = "Assets/Button/Button_Hovered.png";

    SDL_Point defaultNormalSpriteDimension = { 83, 40 };
    SDL_Point defaultHoveredSpriteDimension = { 91, 48 };

    auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
        const SDL_Point& spriteDimensions)
    {
        sprite.Load(filename);
        sprite.SetOriginalDimension();
        sprite.SetSpriteDimension(spriteDimensions);
    };

    InitializingDefaults(m_normalSprite, defaultNormalSpriteFilename, defaultNormalSpriteDimension);
    InitializingDefaults(m_hoveredSprite, defaultHoveredSpriteFilename, defaultHoveredSpriteDimension);
    m_buttonRect = { this->GetPosition().x , this->GetPosition().y,
                    m_normalSprite.GetSpriteDimension().x, m_normalSprite.GetSpriteDimension().y };
}

Button::~Button()
{
    m_hoveredSprite.Unload();
    m_normalSprite.Unload();
}

//default state sprite attributes
void Button::SetNormalAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
    m_normalSprite.Load(filename);
    m_normalSprite.SetOriginalDimension();
    m_normalSprite.SetSpriteDimension(spriteDimensions);
}

//hovered state sprite attributes
void Button::SetHoveredAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
    m_hoveredSprite.Load(filename);
    m_hoveredSprite.SetOriginalDimension();
    m_hoveredSprite.SetSpriteDimension(spriteDimensions);
}

//bounding box (same size as the image) for collision
void Button::SetButtonRect(float angle)
{
    m_buttonRect.x = this->GetPosition().x;
    m_buttonRect.y = this->GetPosition().y;
    m_buttonRect.w = m_normalSprite.GetSpriteDimension().x;
    m_buttonRect.h = m_normalSprite.GetSpriteDimension().y;
}

SDL_Point Button::GetMousePosition()
{
    m_mousePosition = { static_cast<int>(Input::Instance()->GetMousePosition().x), static_cast<int>(Input::Instance()->GetMousePosition().y) };
    return m_mousePosition;
}

//mainly updates button states for the Render() function
bool Button::Update()
{
    GetMousePosition();

    //if mouse in inside the bounding box
    if (static_cast<bool>(SDL_PointInRect(&m_mousePosition, &m_buttonRect)))
    {
        //if mouse is clicked
        if (Input::Instance()->isLeftMouseButtonClicked())
        {
            m_buttonState = Button::ButtonState::Clicked;
            return true;
        }
        m_buttonState = Button::ButtonState::Hovered;
    }
    else
    {
        m_buttonState = Button::ButtonState::Default;
    }

    //if nothing happens to the button
    return false;
}

bool Button::Render()
{
    if (m_buttonState == Button::ButtonState::Hovered)
    {
        m_hoveredSprite.Render({ m_buttonRect.x, m_buttonRect.y });
    }
    else
    {
        m_normalSprite.Render({ m_buttonRect.x, m_buttonRect.y });
    }
    return true;
}
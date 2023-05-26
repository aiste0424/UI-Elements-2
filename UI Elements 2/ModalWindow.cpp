#include "ModalWindow.h"

ModalWindow::ModalWindow()
{
	this->SetPosition({ 700, 50 });
	std::string defaultBackgroundSpriteFilename = "Assets/ModalWindow/ModalWindow_Window.png";
	std::string defaultCloseButtonSpriteFilename = "Assets/ModalWindow/ModalWindow_CloseButton.png";

	SDL_Point defaultBackgroundSpriteDimension = { 160, 350 };
	SDL_Point defaultCloseButtonSpriteDimension = { 48, 48 };

	auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
		const SDL_Point& spriteDimensions, SDL_Rect& rect)
	{
		sprite.Load(filename);
		sprite.SetOriginalDimension();
		sprite.SetSpriteDimension(spriteDimensions);
		rect = { this->GetPosition().x, this->GetPosition().y, sprite.GetSpriteDimension().x,
					sprite.GetSpriteDimension().y };
	};

	InitializingDefaults(m_backgroundSprite, defaultBackgroundSpriteFilename, defaultBackgroundSpriteDimension, m_windowRect);
	InitializingDefaults(m_closeButtonSprite, defaultCloseButtonSpriteFilename, defaultCloseButtonSpriteDimension, m_closeButtonRect);
}

ModalWindow::~ModalWindow()
{
	m_backgroundSprite.Unload();
	m_closeButtonSprite.Unload();
}

void ModalWindow::SetBackgroundAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
	m_backgroundSprite.Load(filename);
	m_backgroundSprite.SetOriginalDimension();
	m_backgroundSprite.SetSpriteDimension(spriteDimensions);
	m_windowRect = { this->GetPosition().x, this->GetPosition().y, m_backgroundSprite.GetSpriteDimension().x,
					m_backgroundSprite.GetSpriteDimension().y };
}

void ModalWindow::SetButtonAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
	m_closeButtonSprite.Load(filename);
	m_closeButtonSprite.SetOriginalDimension();
	m_closeButtonSprite.SetSpriteDimension(spriteDimensions);
	m_closeButtonRect = { this->GetPosition().x, this->GetPosition().y, m_closeButtonSprite.GetSpriteDimension().x,
						m_closeButtonSprite.GetSpriteDimension().y };
}

void ModalWindow::SetOpen()
{
	m_isOpen = true;
}

void ModalWindow::SetClose()
{
	m_isOpen = false;
}

void ModalWindow::HandleEvent(const SDL_Event& event)
{
	if (m_isOpen && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		int mouseX = event.button.x;
		int mouseY = event.button.y;

		if (mouseX >= m_closeButtonRect.x && mouseX <= m_closeButtonRect.x + m_closeButtonRect.w &&
			mouseY >= m_closeButtonRect.y && mouseY <= m_closeButtonRect.y + m_closeButtonRect.h)
		{
			SetClose();
		}
	}
}

bool ModalWindow::Render()
{
	if (m_isOpen)
	{
		m_backgroundSprite.Render(this->GetPosition());
		m_closeButtonSprite.Render(this->GetPosition());
	}
	return false;
}
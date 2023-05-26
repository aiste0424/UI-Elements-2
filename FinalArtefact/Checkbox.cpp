#include "Checkbox.h"
#include "Input.h"

Checkbox::Checkbox()
{
	this->SetPosition({ 50, 50 });
	std::string defaultEnabledSpriteFilename = "Assets/Checkbox/Checkbox_Enabled.png";
	std::string defaultDisabledSpriteFilename = "Assets/Checkbox/Checkbox_Disabled.png";

	SDL_Point defaultEnabledSpriteDimension = { 18, 18 };
	SDL_Point defaultDisabledSpriteDimension = { 18, 18 };

	auto InitializingDefaults = [this](Sprite& sprite, const std::string& filename,
		const SDL_Point& spriteDimensions)
	{
		sprite.Load(filename);
		sprite.SetOriginalDimension();
		sprite.SetSpriteDimension(spriteDimensions);
	};

	InitializingDefaults(m_checkedSprite, defaultEnabledSpriteFilename, defaultEnabledSpriteDimension);
	InitializingDefaults(m_uncheckedSprite, defaultDisabledSpriteFilename, defaultDisabledSpriteDimension);
	m_rect = { this->GetPosition().x, this->GetPosition().y, m_checkedSprite.GetSpriteDimension().x, m_checkedSprite.GetSpriteDimension().y };
}

Checkbox::~Checkbox()
{
	m_checkedSprite.Unload();
	m_uncheckedSprite.Unload();
}

void Checkbox::SetCheckedAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
	m_checkedSprite.Load(filename);
	m_checkedSprite.SetOriginalDimension();
	m_checkedSprite.SetSpriteDimension(spriteDimensions);
	m_rect = { this->GetPosition().x, this->GetPosition().y, m_uncheckedSprite.GetSpriteDimension().x, m_uncheckedSprite.GetSpriteDimension().y };
}

void Checkbox::SetUncheckedAttributes(const std::string& filename, const SDL_Point& spriteDimensions)
{
	m_uncheckedSprite.Load(filename);
	m_uncheckedSprite.SetOriginalDimension();
	m_uncheckedSprite.SetSpriteDimension(spriteDimensions);
}

bool Checkbox::OnChecked()
{
	m_state = Checkbox::State::Checked;
	return true;
}

bool Checkbox::OnUnchecked()
{
	m_state = Checkbox::State::Unchecked;
	return true;
}

bool Checkbox::Update()
{
	GetMousePosition();

	if (static_cast<bool>(SDL_PointInRect(&m_mousePosition, &m_rect)))
	{
		if (Input::Instance()->isLeftMouseButtonClicked())
		{
			if (m_state == State::Checked)
			{
				OnUnchecked();
			}
			else if (m_state == State::Unchecked)
			{
				OnChecked();
			}
		}
	}
	return true;
}

bool Checkbox::Render()
{
	if (m_state == State::Checked)
	{
		m_checkedSprite.Render(this->GetPosition());
	}
	else
	{
		m_uncheckedSprite.Render(this->GetPosition());
	}
	return true;
}

void Checkbox::GetMousePosition()
{
	m_mousePosition = { Input::Instance()->GetMousePosition().x, Input::Instance()->GetMousePosition().y }; //custom input class
}
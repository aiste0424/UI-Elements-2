#pragma once
#include "GameObject.h"
#include "Sprite.h"

class Checkbox : public GameObject
{
public:

	Checkbox();
	~Checkbox();

	enum class State
	{
		Checked,
		Unchecked
	};

	void SetCheckedAttributes(const std::string& filename, const SDL_Point& spriteDimensions);
	void SetUncheckedAttributes(const std::string& filename, const SDL_Point& spriteDimensions);

	bool OnChecked();
	bool OnUnchecked();

	virtual bool Update() override;
	virtual bool Render() override;

private:

	void GetMousePosition(); //gets the mouse position. Needs to be reviewed
	Sprite m_uncheckedSprite;
	Sprite m_checkedSprite;

	SDL_Rect m_rect = { 0, 0, 0, 0 };
	SDL_Point m_mousePosition = { 0, 0 };
	State m_state = State::Unchecked;
};
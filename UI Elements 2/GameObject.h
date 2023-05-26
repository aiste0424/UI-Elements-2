#pragma once
#include <SDL.h>

class GameObject
{

public:

	GameObject() {}
	virtual ~GameObject() = 0 {}
	const SDL_Point& GetPosition() const;
	const SDL_Point& GetDimension() const;
	const double GetAngle() const;

	void SetPosition(const SDL_Point& position);
	void SetDimension(const SDL_Point& dimension);
	void SetAngle(double angle = 0.0);

	virtual bool Update() = 0;
	virtual bool Render() = 0;

protected:

	SDL_Point m_position = { 0, 0 };
	SDL_Point m_dimension = { 0, 0 };
	double m_angle = 0.0;
};
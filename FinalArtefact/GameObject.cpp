#include "GameObject.h"

const SDL_Point& GameObject::GetPosition() const
{
	return m_position;
}

const SDL_Point& GameObject::GetDimension() const
{
	return m_dimension;
}

const double GameObject::GetAngle() const
{
	return m_angle;
}

void GameObject::SetPosition(const SDL_Point& position)
{
	m_position = position;
}

void GameObject::SetDimension(const SDL_Point& dimension)
{
	m_dimension = dimension;
}

void GameObject::SetAngle(double angle)
{
	m_angle = angle;
}
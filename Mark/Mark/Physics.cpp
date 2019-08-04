#include "stdafx.h"
#include "Physics.h"


Mark::AABB::AABB(int width, int height)
{
	m_AABB.setSize(sf::Vector2f(width, height));
	m_AABB.setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));
}


Mark::AABB::~AABB()
{

}

bool Mark::AABB::IsCollide(const Mark::AABB& box)
{
	if (box.GetPosition().x < m_AABB.getPosition().x + m_AABB.getSize().x &&
		box.GetPosition().x + box.GetSize().x > m_AABB.getPosition().x &&
		box.GetPosition().y < m_AABB.getPosition().y + m_AABB.getSize().y &&
		box.GetPosition().y + box.GetSize().y > m_AABB.getPosition().y)
	{
		return true;
	}

	return false;
}
void Mark::AABB::Resize(int width, int height)
{
	m_AABB.setSize(sf::Vector2f(width, height));
	m_AABB.setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));
}
void Mark::AABB::SetPosition(sf::Vector2f pos)
{
	m_AABB.setPosition(pos);
}

const sf::Vector2f& Mark::AABB::GetPosition() const
{
	return m_AABB.getPosition();
}
const sf::Vector2f& Mark::AABB::GetSize() const
{
	return m_AABB.getSize();
}

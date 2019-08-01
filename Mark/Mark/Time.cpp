#include "stdafx.h"
#include "Time.h"


Mark::Time::Time()
{
	m_clock.restart();
	m_elapsed = 0;
}


Mark::Time::~Time()
{
}

float Mark::Time::Restart()
{
	m_elapsed = m_clock.restart().asSeconds();
	return m_elapsed;
}
float Mark::Time::GetElapsedTime() const
{
	return m_elapsed;
}


#include "stdafx.h"
#include "Animation.h"


Mark::Animation::Animation(const Spritesheet& spritesheet, float animDelay)
{
	m_spritesheet = spritesheet;
	m_animationDelay = animDelay;
	m_delay = m_animationDelay;
}

Mark::Animation::Animation(sf::Texture& texture, unsigned char sheetRows, unsigned char sheetCols,sf::Vector2i _spriteSize,bool playOnStart, float animDelay)
{
	m_spritesheet = Spritesheet(texture, sheetRows, sheetCols, _spriteSize);
	m_animationDelay = animDelay;
	m_isPlayed = playOnStart;
	m_delay = m_animationDelay;
}

sf::Sprite& Mark::Animation::GetSprite()
{
	return m_spritesheet.sprite;
}


Mark::Animation::~Animation()
{

}

void Mark::Animation::Play()
{
	m_isPlayed = true;
}

void Mark::Animation::Update(float elapsed)
{
	if (m_isPlayed)
	{
		m_delay += elapsed;

		if (m_delay >= m_animationDelay)
		{
			//Changing frames
			m_spritesheet.sprite.setTextureRect(sf::IntRect(m_spritesheet.currentFrame.x * m_spritesheet.spriteSize.x,
																m_spritesheet.currentFrame.y * m_spritesheet.spriteSize.y,
																m_spritesheet.spriteSize.x,
																m_spritesheet.spriteSize.y));

			if (++m_spritesheet.currentFrame.x >= m_spritesheet.cols)
			{
				m_spritesheet.currentFrame.x = 0;
				m_spritesheet.currentFrame.y++;
				if (m_spritesheet.currentFrame.y >= m_spritesheet.rows)
				{
					m_spritesheet.currentFrame.y = 0;
				}
			}

			m_delay = 0.f;
		}
	}
}

void Mark::Animation::Stop()
{
	m_isPlayed = false;
}

void Mark::Animation::Reset()
{
	m_spritesheet.currentFrame.x = 0;
	m_spritesheet.currentFrame.y = 0;
	m_delay = 0.f;
}

void Mark::Animation::SetAnimDelay(float animDelay)
{
	m_animationDelay = animDelay;
}

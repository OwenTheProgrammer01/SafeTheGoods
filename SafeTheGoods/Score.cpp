#include "pch.h"
#include "Score.h"

Score::~Score()
{
	delete m_pTextTexture;
	m_pTextTexture = nullptr;
}

void Score::Update(float elapsedSec)
{
	m_Position = Point2f{ 15, 450 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("Score:" + std::to_string(m_Score), m_pFont, m_TextColor);
}

void Score::Draw() const
{
	m_pTextTexture->Draw(m_Position);
}

void Score::ShowHighScore()
{
	m_Position = Point2f{ 280, 280 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("High Score:" + std::to_string(m_HighScore), m_pFont, m_TextColor);
}

void Score::SetHighScore()
{
	m_HighScore = m_Score;
	m_Position = Point2f{ 220, 280 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("New High Score:" + std::to_string(m_HighScore), m_pFont, m_TextColor);
}
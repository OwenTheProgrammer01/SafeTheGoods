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
#include "pch.h"
#include "Score.h"

Score::~Score()
{
	delete m_pScoreTexure;
	m_pScoreTexure = nullptr;
}

void Score::Update(float elapsedSec)
{
	delete m_pScoreTexure;
	m_pScoreTexure = new Texture("Score:" + std::to_string(m_Score), "Fonts/CursedTimer.ttf", 36, m_TextColor);
}

void Score::Draw() const
{
	m_pScoreTexure->Draw(m_Position);
}
#include "pch.h"
#include "Mistakes.h"
#include "Level.h"

Mistakes::~Mistakes()
{
	delete m_pTextTexture;
	m_pTextTexture = nullptr;
}

void Mistakes::Update(float elapsedSec)
{
	delete m_pTextTexture;
	m_pTextTexture = new Texture("Errors:" + std::to_string(m_Mistakes) + "/" + std::to_string(MAXMISTAKES), m_pFont, m_TextColor);
}

void Mistakes::Draw() const
{
	m_pTextTexture->Draw(m_Position);
}

bool Mistakes::CheckGameOver() const
{
	if (m_Mistakes >= MAXMISTAKES)
	{
		return true;
	}
	return false;
}
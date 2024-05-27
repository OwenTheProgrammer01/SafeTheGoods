#include "pch.h"
#include "Level.h"

Level::~Level()
{
	delete m_pTextTexture;
	m_pTextTexture = nullptr;
}

void Level::Initialize()
{
	m_Level = 1;
	m_Position = Point2f{ 110, 235 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("PRESS SPACE TO START", m_pFont, m_TextColor);
}

void Level::Update(float elapsedSec)
{
	m_Position = Point2f{ 325, 375 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("Level:" + std::to_string(m_Level), m_pFont, m_TextColor);
}

void Level::Draw() const
{
	m_pTextTexture->Draw(m_Position);
}

void Level::Reset()
{
	m_Level = 1;
	m_Position = Point2f{ 110, 235 };
	delete m_pTextTexture;
	m_pTextTexture = new Texture("PRESS SPACE TO START", m_pFont, m_TextColor);
}
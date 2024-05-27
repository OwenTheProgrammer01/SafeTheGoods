#pragma once
#include "Singleton.h"
#include "Texture.h"

class Score final : public Singleton<Score>
{
public:
	Score() = default;
	~Score();

	void Update(float elapsedSec);
	void Draw() const;

	void Reset() { m_Score = 0; }
	
	void AddScore(int score) { m_Score += score; }
	int GetScore() const { return m_Score; }

	void SetHighScore() 
	{
		m_HighScore = m_Score;
		m_Position = Point2f{ 220, 280 };
		delete m_pTextTexture;
		m_pTextTexture = new Texture("New High Score:" + std::to_string(m_HighScore), m_pFont, m_TextColor);
	}
	int GetHighScore() const { return m_HighScore; }

	Score(const Score& other) = delete;
	Score& operator=(const Score& other) = delete;
	Score(Score&& other) = delete;
	Score& operator=(Score&& other) = delete;
private:
	friend class Singleton<Score>;

	int m_Score{ 0 };
	int m_HighScore{ 0 };
	Point2f m_Position{ 15, 450 };
	Color4f m_TextColor{ 1.0f, 1.0f, 1.0f, 1.0f };
	TTF_Font* m_pFont{ TTF_OpenFont("Fonts/CursedTimer.ttf", 36) };
	Texture* m_pTextTexture{ new Texture("Score:" + std::to_string(m_Score), m_pFont, m_TextColor) };
};
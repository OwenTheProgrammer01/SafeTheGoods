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

	Score(const Score& other) = delete;
	Score& operator=(const Score& other) = delete;
	Score(Score&& other) = delete;
	Score& operator=(Score&& other) = delete;
private:
	friend class Singleton<Score>;

	int m_Score{ 0 };
	Point2f m_Position{ 15, 450 };
	Color4f m_TextColor{ 1.0f, 1.0f, 1.0f, 1.0f };
	Texture* m_pScoreTexure{ new Texture("Score:" + std::to_string(m_Score), "Fonts/CursedTimer.ttf", 36, m_TextColor) };
};
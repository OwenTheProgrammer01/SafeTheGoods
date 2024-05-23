#pragma once
class Score
{
public:
	Score() = default;
	~Score() = default;

	void AddScore(int score) { m_Score += score; }
	int GetScore() const { return m_Score; }

	Score(const Score& other) = delete;
	Score& operator=(const Score& other) = delete;
	Score(Score&& other) = delete;
	Score& operator=(Score&& other) = delete;
private:
	int m_Score = 0;
};
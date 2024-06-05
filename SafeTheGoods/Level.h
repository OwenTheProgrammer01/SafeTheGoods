#pragma once
#include "Singleton.h"
#include "Texture.h"
#include "SoundEffect.h"

class Level final : public Singleton<Level>
{
	public:
	Level() = default;
	~Level();

	void Initialize();

	void Update(float elapsedSec);
	void Draw() const;

	void Reset();

	void SetLevel(int level) { m_Level = level; }
	void NextLevel() { ++m_Level; m_LevelUpSound.Play(0); }
	int GetLevel() const { return m_Level; }

	void SetGameOver(bool gameOver) { m_GameOver = gameOver; }
	bool GetGameOver() const { return m_GameOver; }

	Level(const Level& other) = delete;
	Level& operator=(const Level& other) = delete;
	Level(Level&& other) = delete;
	Level& operator=(Level&& other) = delete;

private:
	friend class Singleton<Level>;

	int m_Level{ 1 };
	bool m_GameOver{ true };
	Point2f m_Position{ 325, 375 };
	Color4f m_TextColor{ 1.0f, 1.0f, 1.0f, 1.0f };
	TTF_Font* m_pFont{ TTF_OpenFont("Fonts/ErbosDraco.ttf", 36) };
	Texture* m_pTextTexture{ new Texture("Level:" + std::to_string(m_Level), m_pFont, m_TextColor) };
	SoundEffect m_LevelUpSound{ "Sounds/Level-Up.wav" };
};
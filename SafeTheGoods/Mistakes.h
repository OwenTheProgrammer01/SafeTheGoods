#pragma once
#include "Singleton.h"
#include "Texture.h"
#include "SoundEffect.h"

class Mistakes final : public Singleton<Mistakes>
{
public:
	Mistakes() = default;
	~Mistakes();

	void Update(float elapsedSec);
	void Draw() const;

	bool CheckGameOver() const;

	void Reset() { m_Mistakes = 0; }
	void AddMistake() { ++m_Mistakes; m_Sound.Play(0); }
	int GetMistakes() const { return m_Mistakes; }

	Mistakes(const Mistakes& other) = delete;
	Mistakes& operator=(const Mistakes& other) = delete;
	Mistakes(Mistakes&& other) = delete;
	Mistakes& operator=(Mistakes&& other) = delete;

private:
	friend class Singleton<Mistakes>;

	int m_Mistakes{ 0 };
	const int MAXMISTAKES{ 5 };
	Point2f m_Position{ 550, 450 };
	Color4f m_TextColor{ 1.0f, 1.0f, 1.0f, 1.0f };
	TTF_Font* m_pFont{ TTF_OpenFont("Fonts/CursedTimer.ttf", 36) };
	Texture* m_pTextTexture{ new Texture("Errors:" + std::to_string(m_Mistakes) + "/" + std::to_string(MAXMISTAKES), m_pFont, m_TextColor) };
	SoundEffect m_Sound{ "Sounds/Error.wav" };
};
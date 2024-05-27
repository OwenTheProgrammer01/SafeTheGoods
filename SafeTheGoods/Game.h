#pragma once
#include "BaseGame.h"
#include "ProductManager.h"
#include "CheckpointManager.h"
#include "Score.h"
#include "Level.h"
#include "Mistakes.h"

class Game : public BaseGame
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update(float elapsedSec) override;
	void Draw() const override;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e) override;
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e) override;
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e) override;
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) override;

private:
	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;

	bool CheckNextLevel();

	// DATA MEMBERS
	ProductManager m_ProductManager;
	CheckpointManager m_CheckpointManager;
	Score m_Score;
	Level m_Level;
	Mistakes m_Mistakes;
};
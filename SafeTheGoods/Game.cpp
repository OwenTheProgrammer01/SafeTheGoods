#include "pch.h"
#include "Game.h"

#include <iostream>

Game::Game(const Window& window)
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	m_ProductManager.Initialize();
	m_CheckpointManager.Initialize();
	m_Level.GetInstance().Initialize();
}

void Game::Cleanup()
{

}

void Game::Update(float elapsedSec)
{
	if (not m_Level.GetInstance().GetGameOver())
	{
		m_Score.GetInstance().Update(elapsedSec);
		m_Mistakes.GetInstance().Update(elapsedSec);
		m_Level.GetInstance().Update(elapsedSec);
		m_ProductManager.Update(elapsedSec);
		m_CheckpointManager.Update(elapsedSec);

		m_Mistakes.GetInstance().CheckGameOver();

		if (CheckNextLevel())
		{
			m_Level.GetInstance().NextLevel();
			m_ProductManager.SetSpeed();
		}
	}
	else
	{
		if (m_Score.GetInstance().GetScore() > m_Score.GetInstance().GetHighScore())
		{
			m_Score.GetInstance().SetHighScore();
		}

		m_Score.GetInstance().Reset();
		m_Mistakes.GetInstance().Reset();
		m_Level.GetInstance().Reset();
		m_ProductManager.Reset();
		m_CheckpointManager.Reset();
	}
}

void Game::Draw() const
{
	ClearBackground();
	m_Score.GetInstance().Draw();
	m_Mistakes.GetInstance().Draw();
	m_Level.GetInstance().Draw();
	m_ProductManager.Draw();
	m_CheckpointManager.Draw();
}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{

}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch ( e.keysym.sym )
	{
	case SDLK_SPACE:
		if (not m_Level.GetInstance().GetGameOver())
			m_ProductManager.CheckProductInCheckpoint(m_CheckpointManager.GetShape());
		else
		{
			Initialize();
			m_Level.GetInstance().SetGameOver(false);
		}
		break;
	}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Game::CheckNextLevel()
{
	int currentScore = Score::GetInstance().GetScore();
	int currentLevel = Level::GetInstance().GetLevel();

	if ((currentScore / 100) > currentLevel - 1)
	{
		return true;
	}
	return false;
}
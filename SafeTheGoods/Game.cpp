#include "pch.h"
#include "Game.h"

#include <iostream>

Game::Game(const Window& window)
	:BaseGame{ window }, m_Window{ 0, 0, window.width, window.height }, m_ShapeCheckpoint{ window.width/2 - 40, window.height/2 - 40, 80, 80 }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	AddCheckpoints();
}

void Game::Cleanup()
{

}

void Game::Update(float elapsedSec)
{
	m_ProductManager.Update(elapsedSec);
	m_CheckpointManager.Update(elapsedSec);
}

void Game::Draw() const
{
	ClearBackground();
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
		m_ProductManager.CheckProductInCheckpoint(m_ShapeCheckpoint);
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

void Game::AddCheckpoints()
{
	m_CheckpointManager.AddCheckpoint(m_ShapeCheckpoint);
}
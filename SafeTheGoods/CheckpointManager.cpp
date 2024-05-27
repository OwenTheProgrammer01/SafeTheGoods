#include "pch.h"
#include "CheckpointManager.h"

void CheckpointManager::Initialize()
{
	AddCheckpoint();
}

void CheckpointManager::Update(float elapsedSec)
{
	for (const auto& checkpoint : m_pCheckpoints)
	{
		checkpoint->Update(elapsedSec);
	}
}

void CheckpointManager::Draw() const
{
	for (const auto& checkpoint : m_pCheckpoints)
	{
		checkpoint->Draw();
	}
}

void CheckpointManager::AddCheckpoint()
{
	m_pCheckpoints.emplace_back(std::make_unique<Checkpoint>(m_Shape));
}

void CheckpointManager::RemoveCheckpoint()
{
	m_pCheckpoints.pop_back();
}

void CheckpointManager::Reset()
{
	m_pCheckpoints.clear();
	m_Shape = Rectf{ 385, 210, 80, 80 };
}
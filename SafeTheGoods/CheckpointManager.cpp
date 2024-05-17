#include "pch.h"
#include "CheckpointManager.h"

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

void CheckpointManager::AddCheckpoint(Rectf& shape)
{
	m_pCheckpoints.emplace_back(std::make_unique<Checkpoint>(shape));
}

void CheckpointManager::RemoveCheckpoint()
{
	m_pCheckpoints.pop_back();
}
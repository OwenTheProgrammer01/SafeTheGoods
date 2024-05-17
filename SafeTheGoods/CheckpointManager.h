#pragma once
#include "Checkpoint.h"

#include <vector>
#include <memory>

class CheckpointManager
{
public:
	CheckpointManager() = default;
	~CheckpointManager() = default;

	void Update(float elapsedSec);
	void Draw() const;

	void AddCheckpoint(Rectf& shape);
	void RemoveCheckpoint();

	CheckpointManager(const CheckpointManager& other) = delete;
	CheckpointManager& operator=(const CheckpointManager& other) = delete;
	CheckpointManager(CheckpointManager&& other) = delete;
	CheckpointManager& operator=(CheckpointManager&& other) = delete;
private:
	std::vector<std::unique_ptr<Checkpoint>> m_pCheckpoints;
};
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

	void AddCheckpoint();
	void RemoveCheckpoint();

	Rectf GetShape() const { return m_ShapeCheckpoint; }

	CheckpointManager(const CheckpointManager& other) = delete;
	CheckpointManager& operator=(const CheckpointManager& other) = delete;
	CheckpointManager(CheckpointManager&& other) = delete;
	CheckpointManager& operator=(CheckpointManager&& other) = delete;
private:
	Rectf m_ShapeCheckpoint{ 385, 210, 80, 80 };

	std::vector<std::unique_ptr<Checkpoint>> m_pCheckpoints;
};
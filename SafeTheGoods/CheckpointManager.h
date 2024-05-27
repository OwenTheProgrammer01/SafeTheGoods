#pragma once
#include "Checkpoint.h"

#include <vector>
#include <memory>

class CheckpointManager
{
public:
	CheckpointManager() = default;
	~CheckpointManager() = default;

	void Initialize();

	void Update(float elapsedSec);
	void Draw() const;

	void AddCheckpoint();
	void RemoveCheckpoint();

	void Reset();

	void SetShape(const Rectf& shape) { m_Shape = shape; }
	Rectf GetShape() const { return m_Shape; }

	CheckpointManager(const CheckpointManager& other) = delete;
	CheckpointManager& operator=(const CheckpointManager& other) = delete;
	CheckpointManager(CheckpointManager&& other) = delete;
	CheckpointManager& operator=(CheckpointManager&& other) = delete;
private:
	Rectf m_Shape{ 385, 210, 80, 80 };

	std::vector<std::unique_ptr<Checkpoint>> m_pCheckpoints;
};
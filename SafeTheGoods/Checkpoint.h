#pragma once
class Checkpoint
{
public:
	Checkpoint(Rectf& shape);
	~Checkpoint() = default;

	void Update(float elapsedSec);
	void Draw() const;

	Checkpoint(const Checkpoint& other) = delete;
	Checkpoint& operator=(const Checkpoint& other) = delete;
	Checkpoint(Checkpoint&& other) = delete;
	Checkpoint& operator=(Checkpoint&& other) = delete;
private:
	Rectf m_Shape;
};
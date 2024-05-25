#include "pch.h"
#include "Checkpoint.h"
#include "utils.h"

Checkpoint::Checkpoint(Rectf& shape)
	: m_Shape(shape) {}

void Checkpoint::Update(float elapsedSec) {}

void Checkpoint::Draw() const
{
	glPushMatrix();
	{
		utils::SetColor(Color4f(0.f, 1.f, 0.f, 1.f));
		utils::DrawRect(m_Shape);
	}
	glPopMatrix();
}
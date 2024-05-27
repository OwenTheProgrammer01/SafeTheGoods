#include "pch.h"
#include "Product.h"
#include "utils.h"

Product::Product(const Rectf& shape, std::string texturePath, Vector2f speed)
	: m_Speed{ speed }, m_MiddlePos(Point2f{ shape.left + shape.width / 2, shape.bottom + shape.height / 2 }), m_Shape(shape), m_TexturePath{ texturePath }, m_ProductType{ }
{
	m_pTexture = std::make_unique<Texture>(m_TexturePath);

	if (m_TexturePath == "Images/RedBottle.png")
		m_ProductType = ProductType::Bad;
	else if (m_TexturePath == "Images/GreenBottle.png")
		m_ProductType = ProductType::Good;
	else if(m_TexturePath == "Images/GoldenBottle.png")
		m_ProductType = ProductType::Lucky;
}

void Product::Update(float elapsedSec)
{
	m_Shape = Rectf{ m_MiddlePos.x - m_Shape.width/2, m_MiddlePos.y - m_Shape.height/2, m_Shape.width, m_Shape.height };

	m_MiddlePos += m_Speed * elapsedSec;
}

void Product::Draw() const
{
	m_pTexture->Draw(m_Shape);
	/// Debug
	//glPushMatrix();
	//{
	//	utils::SetColor(Color4f(1.f, 0.f, 0.f, 1.f));
	//	utils::DrawRect(m_Shape);
	//	utils::DrawLine(m_Shape.left, m_Shape.bottom, m_Shape.left + m_Shape.width, m_Shape.bottom + m_Shape.height);
	//	utils::DrawLine(m_Shape.left, m_Shape.bottom + m_Shape.height, m_Shape.left + m_Shape.width, m_Shape.bottom);
	//	utils::DrawPoint(m_MiddlePos, 5.f);
	//}
	//glPopMatrix();
	/// Debug
}

void Product::SetSpeed(Vector2f speed)
{
	m_Speed = speed;
}

bool Product::IsInCheckpoint(const Rectf& rect) const
{
	return (m_MiddlePos.x > rect.left && m_MiddlePos.x < rect.left + rect.width && m_MiddlePos.y > rect.bottom && m_MiddlePos.y < rect.bottom + rect.height);
}

int Product::GetProductType() const
{
	return static_cast<int>(m_ProductType);
}
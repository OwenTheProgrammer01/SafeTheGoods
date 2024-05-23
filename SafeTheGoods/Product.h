#pragma once
#include "Texture.h"
#include "Vector2f.h"

#include <memory>

class Product
{
public:
	Product(Rectf& shape, std::string texturePath);
	~Product() = default;

	void Update(float elapsedSec);
	void Draw() const;

	bool IsInCheckpoint(const Rectf& other) const;
	bool IsBadProduct() const { return m_TexturePath == "Images/RedBottle.png"; }

	void SetMiddlePos(const Point2f& middlePos) { m_MiddlePos = middlePos; }
	Point2f GetMiddlePos() const { return m_MiddlePos; }
	Rectf GetShape() const { return m_Shape; }

	Product(const Product& other) = delete;
	Product& operator=(const Product& other) = delete;
	Product(Product&& other) = delete;
	Product& operator=(Product&& other) = delete;
private:
	const Vector2f m_Speed;
	Point2f m_MiddlePos;
	Rectf m_Shape;
	std::unique_ptr<Texture> m_pTexture;
	std::string m_TexturePath;
};
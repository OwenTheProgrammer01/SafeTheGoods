#pragma once
#include "Product.h"
#include "SoundEffect.h"

#include <vector>

class ProductManager final
{
public:
	ProductManager();
	~ProductManager() = default;

	void Initialize();

	void Update(float elapsedSec);
	void Draw() const;

	void Reset();

	void CheckProductInCheckpoint(const Rectf& rect);
	void SetSpeed();

	ProductManager(const ProductManager& other) = delete;
	ProductManager& operator=(const ProductManager& other) = delete;
	ProductManager(ProductManager&& other) = delete;
	ProductManager& operator=(ProductManager&& other) = delete;
private:
	void AddProduct();
	void ProductSetup();
	void RemoveProduct();
	void RemoveProductsOffScreen();

	bool IsLevelChanged();

	std::vector<std::unique_ptr<Product>> m_pProducts;

	const Rectf SHAPE;
	std::string m_TexturePath;
	int m_Distance;
	Vector2f m_Speed;
	int m_ChanceBadProduct;
	const int CHANCELUCKYPRODUCT;
	const int MAX_PRODUCTS;
	const int OFFSCREEN;

	int m_Level;

	SoundEffect m_DeleteProductSound{ "Sounds/Delete-Product.wav" };
	SoundEffect m_PlusScoreSound{ "Sounds/Plus-Score.wav" };
};
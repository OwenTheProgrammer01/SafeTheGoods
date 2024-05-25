#pragma once
#include "Product.h"

#include <vector>

class ProductManager final
{
public:
	ProductManager();
	~ProductManager() = default;

	void Update(float elapsedSec);
	void Draw() const;

	void CheckProductInCheckpoint(const Rectf& rect);

	ProductManager(const ProductManager& other) = delete;
	ProductManager& operator=(const ProductManager& other) = delete;
	ProductManager(ProductManager&& other) = delete;
	ProductManager& operator=(ProductManager&& other) = delete;
private:
	void AddProduct(Rectf& shape, std::string texturePath);
	void ProductSetup();
	void RemoveProduct();
	void RemoveProductsOffScreen();

	std::vector<std::unique_ptr<Product>> m_pProducts;

	Rectf m_ShapeProduct;
	std::string m_TexturePath;
	int m_FrequentGoodProduct;
	int m_Distance;
	const int LUCKYPRODUCT;
	const int MAX_PRODUCTS;
	const int OFFSCREEN;
};
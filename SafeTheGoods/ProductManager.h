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

	void AddProduct(Rectf& shape, std::string texturePath);
	void RemoveProduct();
	void RemoveProduct(int index);

	bool CheckIfProductIsInCheckpoint(const Rectf& rect) const;
	bool CheckIfProductIsOfScreen() const;

	ProductManager(const ProductManager& other) = delete;
	ProductManager& operator=(const ProductManager& other) = delete;
	ProductManager(ProductManager&& other) = delete;
	ProductManager& operator=(ProductManager&& other) = delete;
private:
	std::vector<std::unique_ptr<Product>> m_pProducts;

	Rectf m_ShapeProduct;
	std::string m_TexturePath;
	int m_FrequentGoodProduct;
	const int MAX_PRODUCTS;
};
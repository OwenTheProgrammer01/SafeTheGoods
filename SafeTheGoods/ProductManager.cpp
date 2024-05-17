#include "pch.h"
#include "ProductManager.h"

#include <iostream>

ProductManager::ProductManager()
	: m_ShapeProduct(Rectf{ -35, 215, 70, 70 }), m_TexturePath("Images/GreenBottle.png"), m_FrequentGoodProduct(5), MAX_PRODUCTS(10)
{
	AddProduct(m_ShapeProduct, m_TexturePath);
}

void ProductManager::Update(float elapsedSec)
{
	for (const auto& product : m_pProducts)
	{
		product->Update(elapsedSec);
	}

	if (not m_pProducts.size() == 0)
	{
		if (m_pProducts.size() < MAX_PRODUCTS)
		{
			if (m_pProducts.back()->GetMiddlePos().x >= 70)
			{
				auto random = rand() % m_FrequentGoodProduct;
				if (random == 0)
				{
					m_TexturePath = "Images/RedBottle.png";
				}
				else
				{
					m_TexturePath = "Images/GreenBottle.png";
				}
				AddProduct(m_ShapeProduct, m_TexturePath);
			}

		}
		if (m_pProducts[0]->GetMiddlePos().x >= 850)
		{
			RemoveProduct();
		}
	}
}

void ProductManager::Draw() const
{
	for (const auto& product : m_pProducts)
	{
		product->Draw();
	}
}

void ProductManager::AddProduct(Rectf& shape, std::string texturePath)
{
	m_pProducts.emplace_back(std::make_unique<Product>(shape, texturePath));
	std::cout << m_pProducts.size() << std::endl;
}

void ProductManager::RemoveProduct()
{
	m_pProducts.erase(m_pProducts.begin());
}

bool ProductManager::CheckIfProductIsInCheckpoint(const Rectf& rect) const
{
	for (const auto& product : m_pProducts)
	{
		return product->IsInCheckpoint(rect);
	}
}

bool ProductManager::CheckIfProductIsOfScreen() const
{
	for (const auto& product : m_pProducts)
	{
		return true;
	}
}
#include "pch.h"
#include "ProductManager.h"
#include "Score.h"

#include <iostream>

ProductManager::ProductManager()
	: m_ShapeProduct(Rectf{ -35, 215, 70, 70 }), m_TexturePath("Images/GreenBottle.png"), m_FrequentGoodProduct(5), m_Distance(105), LUCKYPRODUCT(30), MAX_PRODUCTS(8), OFFSCREEN(850)
{
	AddProduct(m_ShapeProduct, m_TexturePath);
}

void ProductManager::Update(float elapsedSec)
{
	for (const auto& product : m_pProducts)
	{
		product->Update(elapsedSec);
	}
	ProductSetup();
	RemoveProductsOffScreen();
}

void ProductManager::Draw() const
{
	for (const auto& product : m_pProducts)
	{
		product->Draw();
	}
}


void ProductManager::CheckProductInCheckpoint(const Rectf& rect)
{
	int index = 0;
	for (const auto& product : m_pProducts)
	{
		if (product->IsInCheckpoint(rect))
		{
			product->IsBadProduct() ? Score::GetInstance().AddScore(5) : Score::GetInstance().AddScore(-5);
			m_pProducts.erase(m_pProducts.begin() + index);
			return;
		}
		++index;
	}
	
	std::cout << "No product in checkpoint" << std::endl;
	Score::GetInstance().AddScore(-2);
	return;
}

void ProductManager::AddProduct(Rectf& shape, std::string texturePath)
{
	m_pProducts.emplace_back(std::make_unique<Product>(shape, texturePath));
}

void ProductManager::ProductSetup()
{
	if (m_pProducts.size() < MAX_PRODUCTS)
	{
		if (m_pProducts.back()->GetMiddlePos().x >= m_Distance)
		{
			m_Distance = (rand() % 100) + 105;

			auto randomProduct = rand() % m_FrequentGoodProduct;
			if (randomProduct == 0)
			{
				m_TexturePath = "Images/RedBottle.png";
			}
			else
			{
				auto randomLucky = rand() % LUCKYPRODUCT;
				if (randomLucky == 0)
					m_TexturePath = "Images/GoldenBottle.png";
				else
					m_TexturePath = "Images/GreenBottle.png";
			}
			AddProduct(m_ShapeProduct, m_TexturePath);
		}
	}
} 

void ProductManager::RemoveProduct()
{
	m_pProducts.erase(m_pProducts.begin());
}

void ProductManager::RemoveProductsOffScreen()
{
	if (m_pProducts.size() != m_pProducts.empty())
	{
		if (m_pProducts.front()->GetShape().left >= OFFSCREEN)
		{
			m_pProducts.front()->IsBadProduct() ? Score::GetInstance().AddScore(-5) : Score::GetInstance().AddScore(5);
			
			RemoveProduct();
		}
	}
}
#include "pch.h"
#include "ProductManager.h"
#include "Score.h"
#include "Level.h"
#include "Mistakes.h"

#include <iostream>

ProductManager::ProductManager()
	: SHAPE(Rectf{ -70, 215, 70, 70 }), m_TexturePath("Images/GreenBottle.png"), m_Distance(105), m_Speed{ 100, 0 }, m_ChanceBadProduct(6), CHANCELUCKYPRODUCT(25), MAX_PRODUCTS(8), OFFSCREEN(850), m_Level(1)
{
	Initialize();
}

void ProductManager::Initialize()
{
	AddProduct();
}

void ProductManager::Update(float elapsedSec)
{
	for (const auto& product : m_pProducts)
	{
		product->Update(elapsedSec);
	}
	ProductSetup();
	RemoveProductsOffScreen();

	if (IsLevelChanged())
	{
		if (m_Level % 5 == 0 and m_ChanceBadProduct > 3)
		{
			m_ChanceBadProduct -= 1;
		}
		SetSpeed();
	}
}

void ProductManager::Draw() const
{
	for (const auto& product : m_pProducts)
	{
		product->Draw();
	}
}

void ProductManager::Reset()
{
	m_pProducts.clear();
	m_Level = 1;
	m_Speed = Vector2f{ 100, 0 };
	m_Distance = 105;
	m_ChanceBadProduct = 6;
}

void ProductManager::CheckProductInCheckpoint(const Rectf& rect)
{
	int index = 0;
	for (const auto& product : m_pProducts)
	{
		if (product->IsInCheckpoint(rect))
		{
			auto productType = product->GetProductType();
			switch (productType)
			{
			case 0: Score::GetInstance().AddScore(10); break;
			case 1: Mistakes::GetInstance().AddMistake(); break;
			case 2: Score::GetInstance().AddScore(50); break;
			}
			m_DeleteProductSound.Play(0);
			m_pProducts.erase(m_pProducts.begin() + index);
			return;
		}
		++index;
	}
	
	Mistakes::GetInstance().AddMistake();
	return;
}

void ProductManager::SetSpeed()
{
	m_Speed.x += 10;
	for (const auto& product : m_pProducts)
	{
		product->SetSpeed(m_Speed);
	}
}

void ProductManager::AddProduct()
{
	m_pProducts.emplace_back(std::make_unique<Product>(SHAPE, m_TexturePath, m_Speed));
}

void ProductManager::ProductSetup()
{
	if (m_pProducts.size() < MAX_PRODUCTS)
	{
		if (m_pProducts.back()->GetMiddlePos().x >= m_Distance)
		{
			m_Distance = (rand() % 100) + 105;

			auto randomProduct = rand() % m_ChanceBadProduct;
			if (randomProduct == 0)
			{
				m_TexturePath = "Images/RedBottle.png";
			}
			else
			{
				auto randomLucky = rand() % CHANCELUCKYPRODUCT;
				if (randomLucky == 0)
					m_TexturePath = "Images/GoldenBottle.png";
				else
					m_TexturePath = "Images/GreenBottle.png";
			}
			AddProduct();
		}
	}
} 

void ProductManager::RemoveProduct()
{
	m_pProducts.erase(m_pProducts.begin());
}

void ProductManager::RemoveProductsOffScreen()
{
	if (not m_pProducts.empty())
	{
		if (m_pProducts.front()->GetShape().left >= OFFSCREEN)
		{
			auto productType = m_pProducts.front()->GetProductType();
			switch (productType)
			{
			case 0: Mistakes::GetInstance().AddMistake(); break;
			case 1: Score::GetInstance().AddScore(10); m_PlusScoreSound.Play(0); break;
			case 2: break;
			}
			RemoveProduct();
		}
	}
}

bool ProductManager::IsLevelChanged()
{
	if (Level::GetInstance().GetLevel() != m_Level)
	{
		m_Level = Level::GetInstance().GetLevel();
		return true;
	}
	return false;
}
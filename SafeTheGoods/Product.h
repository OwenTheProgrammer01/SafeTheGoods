#pragma once
class Product
{
public:
	Product() = default;
	~Product() = default;
	Product(const Product& other) = delete;
	Product& operator=(const Product& other) = delete;
	Product(Product&& other) = delete;
	Product& operator=(Product&& other) = delete;

	void Update(float elapsedSec);
	void Draw() const;
};
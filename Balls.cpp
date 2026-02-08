#include "Balls.h"

void Balls::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % window.getSize().x - this->shape.getRadius()),
		static_cast<float>(rand() % window.getSize().y - this->shape.getRadius())));
}

//Constructor and Distructors
Balls::Balls(const sf::RenderWindow& window)
{
	this->initShape(window);
}

Balls::~Balls()
{
}

const sf::CircleShape Balls::getShape() const
{
	return this->shape;
}

//Functions
void Balls::update()
{
}

void Balls::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

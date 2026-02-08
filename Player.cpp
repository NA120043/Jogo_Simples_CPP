#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->hpMax = 10;
	this->hp = hpMax;
	this->points = 0;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

//Constructors and Destructors
Player::Player(float x, float y)
{
	this->shape.setPosition(sf::Vector2<float>(x, y));

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

//Functions
void Player::updateInput()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->shape.move(sf::Vector2<float>(-this->movementSpeed, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->shape.move(sf::Vector2<float>(this->movementSpeed, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->shape.move(sf::Vector2<float>(0.f, -this->movementSpeed));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->shape.move(sf::Vector2<float>(0.f, this->movementSpeed));
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->shape.getPosition().x <= 0.f)
	{
		this->shape.setPosition(sf::Vector2<float>(0, this->shape.getPosition().y));
	}
	//Top
	if (this->shape.getPosition().y <= 0.f)
	{
		this->shape.setPosition(sf::Vector2<float>(this->shape.getPosition().x, 0));
	}
	//Right
	if (this->shape.getPosition().x + this->shape.getSize().x >= target->getSize().x)
	{
		this->shape.setPosition(sf::Vector2<float>(target->getSize().x - this->shape.getSize().x, this->shape.getPosition().y));
	}
	//Bottom
	if (this->shape.getPosition().y + this->shape.getSize().y >= target->getSize().y)
	{
		this->shape.setPosition(sf::Vector2<float>(this->shape.getPosition().x, target->getSize().y - this->shape.getSize().y));
	}
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();

	//Window bounds collision
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

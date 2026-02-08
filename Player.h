#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Player
{
private:
	//Variables
	sf::RectangleShape shape;

	float movementSpeed;
	int hp;
	int hpMax;
	int points;

	//Functions
	void initVariables();
	void initShape();

public:
	//Constructor and Destructors
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	//Functions
	const sf::RectangleShape& getShape() const;

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};


#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Balls
{
private:
	//Variables
	sf::CircleShape shape;

	//Functions
	void initShape(const sf::RenderWindow& window);
public:
	//Constructor and Distructors
	Balls(const sf::RenderWindow& window);
	virtual ~Balls();

	const sf::CircleShape getShape() const;

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};


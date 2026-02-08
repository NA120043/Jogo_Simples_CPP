#include<iostream>
#include<ctime>
#include<vector>

#include"Player.h"
#include"Balls.h"

class Game
{
private:
	sf::VideoMode VideoMode;
	sf::RenderWindow* window;
	bool endGame;

	Player player;

	std::vector<Balls> balls;
	float spawnTimeMax;
	float spawnTimer;
	int maxBalls;

	void initVariables();
	void initWindow();

public:
	//Constructor and Destructors
	Game();
	~Game();

	//Accessors

	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void spawnBalls();
	void updateCollision();
	void update();
	void render();
};

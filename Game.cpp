#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimeMax = 10.f;
	this->spawnTimer = this->spawnTimeMax;
	this->maxBalls = 10;
}

void Game::initWindow()
{
	this->VideoMode = sf::VideoMode({ 800, 600 });
	this->window = new sf::RenderWindow(this->VideoMode, "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructor and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Functions
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (const std::optional<sf::Event> sfmlEvent = this->window->pollEvent())
	{
		if (sfmlEvent->is<sf::Event::Closed>())
		{
			this->window->close();
			break;
		}
		else if (const auto* keypressed = sfmlEvent->getIf<sf::Event::KeyPressed>())
		{
			if (keypressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}

void Game::spawnBalls()
{
	//Timer
	if (this->spawnTimer < this->spawnTimeMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->balls.size() < this->maxBalls)
		{
			this->balls.push_back(Balls(*this->window));

			this->spawnTimer = 0.f;
		}
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->balls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().findIntersection(this->balls[i].getShape().getGlobalBounds()))
		{
			this->balls.erase(this->balls.begin() + i);
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->spawnBalls();
	this->player.update(this->window);
	this->updateCollision();
}

void Game::render()
{
	this->window->clear();

	//Render stuff
	this->player.render(this->window);

	for (auto i : this->balls)
	{
		i.render(*this->window);
	}

	this->window->display();
}

#include "GraphicView.h"


GraphicView::GraphicView(void)
{
}

void GraphicView::Init(int height, int width)
{
	this->window = new sf::RenderWindow(sf::VideoMode(height, width), "VI51 - PacMan");
	this->window->setVerticalSyncEnabled(true);

	this->wallTexture.loadFromFile("../TP-VI51/res/wall.png");
	this->sprite.push_back(sf::Sprite());
	this->sprite[this->sprite.size()-1].setTexture(this->wallTexture);
	this->pillTexture.loadFromFile("../TP-VI51/res/pill.png");
	this->sprite.push_back(sf::Sprite());
	this->sprite[this->sprite.size()-1].setTexture(this->pillTexture);
	this->playerTexture.loadFromFile("../TP-VI51/res/player.png");
	this->sprite.push_back(sf::Sprite());
	this->sprite[this->sprite.size()-1].setTexture(this->playerTexture);
}

int GraphicView::CheckEvent()
{
	sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
		{
            this->window->close();
			return 1;
		}
    }
	return 0;
}

void GraphicView::Draw()
{
	window->clear(sf::Color::Black);

	std::vector<Body*>* listOfBodys = this->world->GetListOfBodys();
	if (this->bodyShape.size() != listOfBodys->size())
	{
		this->bodyShape.clear();
		for (int i=0; i<listOfBodys->size(); ++i)
		{
			this->bodyShape.push_back(sf::CircleShape(2));
			this->bodyShape.at(this->bodyShape.size()-1).setFillColor(sf::Color(255, 255, 255));
		}
	}

	for (int idCurrentBody=0; idCurrentBody<listOfBodys->size(); ++idCurrentBody)
	{
		std::vector<float> pos = listOfBodys->at(idCurrentBody)->GetPosition();
		this->bodyShape[idCurrentBody].setPosition(pos[0], pos[1]);
		window->draw(this->bodyShape[idCurrentBody]);
	}

	int** map = this->world->GetMap();
	for (int i=0; i<this->world->getHeight(); ++i)
	{
		for (int j=0; j<this->world->getWidth(); ++j)
		{
			if (map[i][j] == 0)
				continue;
			this->sprite[map[i][j]-1].setPosition(i*this->wallTexture.getSize().x, j*this->wallTexture.getSize().x);
			window->draw(this->sprite[map[i][j]-1]);
		}
	}

	window->display();
}

void GraphicView::SetWorld(World* world)
{
	this->world = world;
}

GraphicView::~GraphicView(void)
{
	this->window->clear();
	delete this->window;
}

#include "World.h"


World::World(void)
{
}

void World::CreateMap()
{
	loadLevel();
	for (std::vector<Body*>::iterator currentBody = this->listOfBodys.begin(); currentBody != this->listOfBodys.end(); ++currentBody)
		(*currentBody)->setMap(&this->map);
}

void World::loadLevel() 
{
	
	std::ifstream fichier("../TP-VI51/res/map.txt", std::ios::in);
	

	if (fichier)
	{
		fichier >> height >> width;

		//allocate the array
		map = new int*[width];
		for (int i = 0; i < width; i++)
			map[i] = new int[height];

		
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				int tmp;
				fichier >> tmp;
				map[y][x] = tmp;
				if (tmp >= 3)
					CreateBody(y, x);
			}
		}

		fichier.close();

	}
	else
		std::cout << "Impossible d'ouvrir le level" << std::endl;
    
}

Body* World::CreateBody(int x, int y)
{
	Body* b = new Body(PacMan());
	b->SetPosition(x, y);
	this->listOfBodys.push_back(b);
	return b;
}


void World::CollecteInfluance()
{
	this->listOfInfluances.clear();
	for (std::vector<Body*>::iterator currentBody = this->listOfBodys.begin(); currentBody != this->listOfBodys.end(); ++currentBody)
	{
		float dx, dy, velocity;
		(*currentBody)->GetInfluance(&dx, &dy, &velocity);
		this->listOfInfluances.push_back(glm::vec3(dx, dy, velocity));
	}
}

void World::ComputeCollision()
{
	for (int i=0; i<this->listOfBodys.size(); ++i)
	{
		Body* b = this->listOfBodys[i];
		int posX = (int)b->GetPosition()[0];
		int posY = (int)b->GetPosition()[1];
		float dx = this->listOfInfluances[i].x, dy = this->listOfInfluances[i].y, velocity = this->listOfInfluances[i].z;
		int newPosX = posX + dx*velocity;
		int newPosY = posY + dy*velocity;
		if (this->map[newPosX][newPosY] == WALL)
			this->listOfInfluances[i].z = 0;
	}
}

void World::MoveBodys()
{
	for (int i=0; i<this->listOfBodys.size(); ++i)
	{
		Body* b = this->listOfBodys[i];
		int posX = (int)b->GetPosition()[0];
		int posY = (int)b->GetPosition()[1];
		this->map[posX][posY] = EMPTY;
		float dx = this->listOfInfluances[i].x, dy = this->listOfInfluances[i].y, velocity = this->listOfInfluances[i].z;
		int newPosX = posX + dx*velocity;
		int newPosY = posY + dy*velocity;
		this->listOfBodys[i]->SetPosition(newPosX, newPosY);
		this->map[newPosX][newPosY] = PLAYER;
	}
}

int** World::GetMap() 
{
	return this->map;
}

std::vector<Body*>* World::GetListOfBodys() 
{
	return &this->listOfBodys;
}

World::~World(void)
{
}

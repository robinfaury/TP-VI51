#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <glm.hpp>

#include "Body.h"
#include "PacMan.h"

class World
{
private:
	enum {EMPTY, WALL, PILL, PLAYER};
	int** map;
	int height;
	int width;
	std::vector<Body*> listOfBodys;
	std::vector<glm::vec3> listOfInfluances;

public:
	World(void);

	void CreateMap();
	void loadLevel();
	Body* CreateBody(int x, int y);

	void CollecteInfluance();
	void ComputeCollision();
	void MoveBodys();

	int** GetMap();
	std::vector<Body*>* GetListOfBodys();

	int getHeight() {return this->height;}
	int getWidth() {return this->width;}

	~World(void);
};

#endif
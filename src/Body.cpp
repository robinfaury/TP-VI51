#include "Body.h"


Body::Body(Semantic type)
{
	this->type = type;
}

std::vector<glm::vec3>* Body::GetPerception()
{
	/*this->FoV.clear();
	int x = this->posX;
	while(--x <= 0 || *this->map[x][this->posY] != 1)
		FoV.push_back(glm::vec3(x, this->posY, *this->map[x][this->posY]));
	x = this->posX;
	while(++x <= 0 || *this->map[x][this->posY] != 1)
		FoV.push_back(glm::vec3(x, this->posY, *this->map[x][this->posY]));
	int y = this->posY;
	while(--y <= 0 || *this->map[this->posX][y] != 1)
		FoV.push_back(glm::vec3(this->posX, y, *this->map[this->posX][y]));
	y = this->posY;
	while(++y <= 0 || *this->map[this->posX][y] != 1)
		FoV.push_back(glm::vec3(this->posX, y, *this->map[this->posX][y]));*/
	return &FoV;
}

void Body::SetInfluance(float dx, float dy, float velocity)
{
	this->dx = dx;
	this->dy = dy;
	this->velocity = velocity;
}

void Body::GetInfluance(float *dx, float *dy, float *velocity)
{
	*dx = this->dx;
	*dy = this->dy;
	*velocity = this->velocity;
}

void Body::SetPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;
}

void Body::GetPosition(float &x, float &y)
{
	x = this->posX;
	y = this->posY;
}

std::vector<float> Body::GetPosition()
{
	std::vector<float> ret;
	ret.push_back(this->posX);
	ret.push_back(this->posY);
	return ret;
}
	
void Body::SetSemantic(Semantic type)
{
	this->type = type;
}

Semantic* Body::GetSemantic()
{
	return &this->type;
}

Body::~Body(void)
{
}

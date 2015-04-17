#include "Body.h"


Body::Body(Semantic type)
{
	this->type = type;
}

std::vector<int>* Body::GetPerception()
{
	this->FoV.clear();
	
	FoV.push_back((*this->map)[this->posX-1][this->posY-1]);
	FoV.push_back((*this->map)[this->posX][this->posY-1]);
	FoV.push_back((*this->map)[this->posX+1][this->posY-1]);
	FoV.push_back((*this->map)[this->posX-1][this->posY]);
	FoV.push_back((*this->map)[this->posX+1][this->posY]);
	FoV.push_back((*this->map)[this->posX-1][this->posY+1]);
	FoV.push_back((*this->map)[this->posX][this->posY+1]);
	FoV.push_back((*this->map)[this->posX+1][this->posY+1]);
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

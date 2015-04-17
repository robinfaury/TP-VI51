#ifndef BODY_H_
#define BODY_H_

#include <vector>
#include <glm.hpp>

#include "PhysicalObject.h"

class Body:  public PhysicalObject
{
private:
	Body(void) {}
	float dx;
	float dy;
	float velocity;
	int*** map;
	std::vector<glm::vec3> FoV;

public:
	Body(Semantic type);

	std::vector<glm::vec3>* GetPerception();
	void SetInfluance(float dx, float dy, float velocity);
	void GetInfluance(float *dx, float *dy, float *velocity);

	virtual void SetPosition(float x, float y);
	virtual void GetPosition(float &x, float &y);
	virtual std::vector<float> GetPosition();
	
	virtual void SetSemantic(Semantic type);
	virtual Semantic* GetSemantic();

	void setMap(int*** map) {this->map = map;}

	~Body(void);
};

#endif
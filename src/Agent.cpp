#include "Agent.h"


Agent::Agent(Body* body)
{
	this->body = body;
}

void Agent::Life()
{
	std::vector<glm::vec3>* FoV = this->body->GetPerception();

	
	switch(rand()%5)
	{
	case 0:
		this->body->SetInfluance(-1, 0, 1);
		break;
	case 1:
		this->body->SetInfluance(0, -1, 1);
		break;
	case 2:
		this->body->SetInfluance(1, 0, 1);
		break;
	case 3:
		this->body->SetInfluance(0, 1, 1);
		break;
	default:
		this->body->SetInfluance(0, 0, 0);
	}
}

Agent::~Agent(void)
{
}

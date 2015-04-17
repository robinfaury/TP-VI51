#include "Agent.h"


Agent::Agent(Body* body)
{
	this->body = body;
}

void Agent::Life()
{
	std::vector<int>* FoV = this->body->GetPerception();

	if ((*FoV)[1] == PILL)
		this->body->SetInfluance(0, -1, 1);
	if ((*FoV)[3] == PILL)
		this->body->SetInfluance(-1, 0, 1);
	if ((*FoV)[4] == PILL)
		this->body->SetInfluance(1, 0, 1);
	if ((*FoV)[6] == PILL)
		this->body->SetInfluance(0, 1, 1);
}

Agent::~Agent(void)
{
}

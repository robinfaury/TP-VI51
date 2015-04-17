#ifndef AGENT_H_
#define AGENT_H_

#include "Body.h"

enum {EMPTY, WALL, PILL, PLAYER};

class Agent
{
private:
	Body* body;
	Agent(void) {}

public:
	Agent(Body* body);

	void Life();

	~Agent(void);
};

#endif
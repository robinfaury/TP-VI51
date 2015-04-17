#include "Simulator.h"


Simulator::Simulator(int numberOfAgents)
{
	this->numberOfAgents = numberOfAgents;
	this->SFMLView.Init(30*27, 30*30);
}

void Simulator::CreateWorld()
{
	this->world.CreateMap();

	for (std::vector<Body*>::iterator currentBody = this->world.GetListOfBodys()->begin(); currentBody != this->world.GetListOfBodys()->end(); ++currentBody)
		this->agents.push_back(Agent((*currentBody)));
	
	this->SFMLView.SetWorld(&this->world);
}

void Simulator::Run()
{
	std::chrono::system_clock::time_point start_time, end_time;
	int eventID = 0;

	while(eventID != 1)
	{
		start_time = std::chrono::high_resolution_clock::now();

		eventID = this->SFMLView.CheckEvent();

		for (std::vector<Agent>::iterator currentAgent = this->agents.begin(); currentAgent != this->agents.end(); ++currentAgent)
			(*currentAgent).Life();

		this->world.CollecteInfluance();
		this->world.ComputeCollision();
		this->world.MoveBodys();

		this->SFMLView.Draw();

		end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

Simulator::~Simulator(void)
{
}

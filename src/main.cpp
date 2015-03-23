#include "Simulator.h"

int main(int argc, char* argv[]) 
{
	Simulator simulatorOfLemming(10000);
	simulatorOfLemming.CreateWorld();
	simulatorOfLemming.Run();

	return EXIT_SUCCESS;
}


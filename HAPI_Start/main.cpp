
// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "Graphics.h"
#include "World.h"
#include "Entity.h"
#include "Entity_Player.h"


// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

void HAPI_Main()
{
	World Sim;

	Sim.Run();

}



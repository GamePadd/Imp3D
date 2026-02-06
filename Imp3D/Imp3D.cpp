#include <iostream>
#include <string>

#include "Imp3D.h"
#include "ECS_World/World.h"
#include "ECS_World/Entities.h"
#include "ConsoleLogger.h"

int main() {

	Imp::World* world = Imp::create_world();
	Imp::entity_id player_entity = Imp::create_entity(world);
	player_entity = Imp::create_entity(world);
	Imp::destroy_entity(world, player_entity);
	player_entity = Imp::create_entity(world);
	player_entity = Imp::create_entity(world);

	Imp::destroy_world(world);

	return 0;
}
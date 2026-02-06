#include <iostream>
#include <string>

#include "Imp3D.h"
#include "Entities.h"
#include "ConsoleLogger.h"

int main() {
	Imp::ConsoleLogger& Logger = Imp::ConsoleLogger::Instance();

	Imp::entity_id player_entity = Imp::create_entity();
	player_entity = Imp::create_entity();
	Imp::destroy_entity(player_entity);
	player_entity = Imp::create_entity();
	player_entity = Imp::create_entity();

	return 0;
}
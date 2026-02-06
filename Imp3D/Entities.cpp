#include "Entities.h"
#include "ConsoleLogger.h"

namespace Imp {
	ConsoleLogger& Logger = ConsoleLogger::Instance();

	std::vector<uint8_t> entities = { 0 };
	std::queue<uint32_t> empty_entities_spots;

	entity_id create_entity() {
		if (!empty_entities_spots.empty()) {
			uint32_t empty_spot = empty_entities_spots.front();
			empty_entities_spots.pop();
			++entities[empty_spot];
			entity_id new_entity = CREATE_ID(entities[empty_spot], empty_spot);

			Logger.Log("Spawned Entity: " + std::to_string(GET_INDEX(new_entity)), Imp::LOG::INFO);

			return new_entity;
		}

		entities.push_back(1);
		entity_id new_entity = CREATE_ID(1, entities.size() - 1);

		Logger.Log("Spawned Entity: " + std::to_string(GET_INDEX(new_entity)), Imp::LOG::INFO);

		return new_entity;
	}

	void destroy_entity(entity_id entity) {
		uint32_t entity_index = GET_INDEX(entity);

		Logger.Log("Deleted Entity: " + std::to_string(GET_INDEX(entity_index)), Imp::LOG::INFO);

		++entities[entity_index];
		empty_entities_spots.push(entity_index);
	}
}
#pragma once

#include <vector>
#include <queue>

namespace Imp {
	struct World {
		std::vector<uint8_t> entities = { 0 };
		std::queue<uint32_t> empty_entities_spots;
	};

	World* create_world();
	void destroy_world(World* world);
}
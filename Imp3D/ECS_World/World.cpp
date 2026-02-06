#include "World.h"

#include <vector>
#include <queue>

namespace Imp {
	World* create_world() {
		World* world = new World();
		return world;
	}

	void destroy_world(World* world) {
		delete world;
	}
}
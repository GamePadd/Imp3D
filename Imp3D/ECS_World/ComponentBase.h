#pragma once
#include "Entities.h"

namespace Imp {
	class ComponentBase {
		protected:
			generational_ptr component_to_entity[MAX_ENTITIES];
			generational_ptr entity_to_component[MAX_ENTITIES];
			uint32_t last_component = 0;
		public:
			virtual void destroy(entity_id) = 0;
			virtual void free() = 0;

			entity_id get_entity(uint32_t);
			bool has_component(entity_id);
	};
}
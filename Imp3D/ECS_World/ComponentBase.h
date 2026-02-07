#pragma once
#include "Entities.h"

namespace Imp {
	class ComponentBase {
		protected:
			generational_ptr component_to_entity[MAX_ENTITIES];
			generational_ptr entity_to_component[MAX_ENTITIES];
			uint32_t last_component = 0;
		public:
			virtual void Destroy(entity_id) = 0;
			virtual void Free() = 0;

			entity_id GetEntity(uint32_t);
			bool HasComponent(entity_id);
	};
}
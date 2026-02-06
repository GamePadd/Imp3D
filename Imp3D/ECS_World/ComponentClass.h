#pragma once
#include "ComponentBase.h"

namespace Imp {
	template<typename T>
	class Component : ComponentBase {
		private:
			std::vector<T> components{ {} };
		public:
			T* create(entity_id, T);
			T* get_component(entity_id);

			void(*destroy_function)(T*);

			void destroy(entity_id);
			void free();
	};
}
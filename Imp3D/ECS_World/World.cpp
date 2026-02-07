#include <typeinfo>
#include <vector>
#include <queue>

#include "World.h"
#include "../ConsoleLogger.h"

namespace Imp {
	World::World() {
		ConsoleLogger::Instance().Log("New world created!", LOG::INFO);
	}

	const std::unordered_map<std::string, system_t> World::GetSystems() const {
		return systems;
	}

	const std::unordered_map<std::string, ComponentBase*> World::GetComponents() const {
		return components;
	}

	const std::vector<uint8_t>& World::GetEntities() const {
		return entities;
	}

	World::~World() {
		std::unordered_map<std::string, ComponentBase*>::iterator level_component_iterator = components.begin();
		while (level_component_iterator != components.end()) {
			level_component_iterator->second->Free();
			delete level_component_iterator->second;
			++level_component_iterator;
		}

		ConsoleLogger::Instance().Log("World deleted", LOG::INFO);
	}

	void World::RegisterSystem(system_t system, const char* system_name) {
		systems.insert({ system_name,system });
		ConsoleLogger::Instance().Log("Registered new system: " + std::string(system_name), LOG::INFO);
	}

	void World::UnregisterSystem(const char* system_name) {
		systems.erase(system_name);
		ConsoleLogger::Instance().Log("Deleted system: " + std::string(system_name), LOG::INFO);
	}

	entity_id World::CreateEntity() {
		if (!empty_entities_spots.empty()) {
			uint32_t empty_spot = empty_entities_spots.front();
			empty_entities_spots.pop();
			++entities[empty_spot];
			entity_id new_entity = CREATE_ID(entities[empty_spot], empty_spot);

			ConsoleLogger::Instance().Log("Spawned Entity: " + std::to_string(GET_INDEX(new_entity)), Imp::LOG::INFO);

			return new_entity;
		}

		entities.push_back(1);
		entity_id new_entity = CREATE_ID(1, entities.size() - 1);

		ConsoleLogger::Instance().Log("Spawned Entity: " + std::to_string(GET_INDEX(new_entity)), Imp::LOG::INFO);

		return new_entity;
	}

	void World::DestroyEntity(entity_id entity) {
		uint32_t entity_index = GET_INDEX(entity);
		++entities[entity_index];
		empty_entities_spots.push(entity_index);

		std::unordered_map<std::string, ComponentBase*>::iterator component_iterator = components.begin();

		while (component_iterator != components.end()) {
			component_iterator->second->Destroy(entity);
			++component_iterator;
		}

		ConsoleLogger::Instance().Log("Deleted Entity: " + std::to_string(GET_INDEX(entity_index)), Imp::LOG::INFO);
	}
}
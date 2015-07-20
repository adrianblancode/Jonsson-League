#include "inventory.hpp"

namespace jonsson_league {

	Inventory::Inventory() : Container() {
	}

	Inventory::Inventory(int num_slots, int max_weight) : Container(num_slots, max_weight) {
		
	}

	int Inventory::get_stats_health() const {
		int health_increase = 0;
		for ( Item* item : *get_items() ) {
			health_increase += item->get_health();
		}
		return health_increase;
	}

	int Inventory::get_stats_strength() const {
		int strength_increase = 0;
		for ( Item* item : *get_items() ) {
			strength_increase += item->get_strength();
		}
		return strength_increase;
	}

}

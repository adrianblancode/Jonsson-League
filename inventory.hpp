#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"
#include "container.hpp"

namespace jonsson_league {

	// Contains one single tile of the map
	class Inventory : public Container {
	private:
	public:
		Inventory();
		Inventory(int num_slots, int max_weight);
		int get_stats_health() const;
		int get_stats_strength() const;
	};

}

#endif // INVENTORY_H

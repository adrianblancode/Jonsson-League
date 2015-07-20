#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "item.hpp"

namespace jonsson_league {

	// Contains one single tile of the map
	class Container {
	private:
		int slot_limit_;
		int weight_limit_;
		std::vector<Item*> * items_;
	public:
		Container();
		Container(int num_slots, int max_weight);
		virtual ~Container();
		bool contains(Item* item) const;
		int get_slot_limit() const;
		int set_slot_limit(int);
		int get_weight_limit() const;
		int set_weight_limit(int);
		bool add_item(Item* item);
		std::vector<Item*> * get_items() const;
		Item* get_item_by_name(std::string) const;
		bool remove_item(Item* item);
		int get_weight() const;
		int get_value() const;
		int get_number_of_items() const;
	};

}

#endif // CONTAINER_H

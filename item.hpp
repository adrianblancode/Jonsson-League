#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace jonsson_league {

	// Base class for all items
	class Item {
	private:
		std::string name_;
		std::string description_;
		int weight_;
		int value_;
		int health_;
		int strength_;
	public:
		Item();
		Item(std::string name, std::string description, int weight, int value, int health, int strength);
		std::string get_name() const;
		std::string get_description() const;
		int get_weight() const;
		int get_value() const;
		int get_health() const;
		int get_strength() const;
	};

}

#endif // ITEM_H

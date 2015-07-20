#include "item.hpp"

namespace jonsson_league {

	Item::Item() {
		name_ = "Unknown";
		description_ = "An unknown item";
		weight_ = 0;
		value_ = 0;
		health_ = 0;
		strength_ = 0;
	}

	Item::Item(std::string name, std::string description, int weight, int value, int health, int strength) {
		name_ = name;
		description_ = description;
		weight_ = weight;
		value_ = value;
		health_ = health;
		strength_ = strength;
	}


	std::string Item::get_name() const {
		return name_;
	}

	std::string Item::get_description() const {
		return description_;
	}

	int Item::get_weight() const {
		return weight_;
	}

	int Item::get_value() const {
		return value_;
	}

	int Item::get_health() const {
		return health_;
	}

	int Item::get_strength() const {
		return strength_;
	}

}

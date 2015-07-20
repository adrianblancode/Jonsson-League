#include "character.hpp"

namespace jonsson_league {

    Character::Character() {
        type_ = "unknown";
        name_ = "unknown";
        name_of_attack_ = "attacks";
        weight_ = 1;
        health_ = 1;
		max_health_ = 1;
        strength_ = 1;
        aggression_ = false;
        current_environment_ = NULL;
    }

    Character::Character(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment) {
        type_ = type;
        name_ = name;
        weight_ = 10;
        name_of_attack_ = name_of_attack;
        health_ = health;
		max_health_ = health;
        strength_ = strength;
        aggression_ = false; //TODO NOT AN ARGUMENT
        current_environment_ = current_environment;
    }

    Character::~Character() {}

    void Character::say() const {}

    std::string Character::get_type() const {
    	return type_;
    }

    std::string Character::get_name() const {
    	return name_;
    }

    int Character::get_weight() const {
        return weight_ + inventory_.get_weight();
    }

	int Character::get_base_weight() const {
		return weight_;
	}

	void Character::set_base_weight(int base_weight) {
		weight_ = base_weight;
	}

    int Character::get_health() const {
    	return health_;
    }

    void Character::set_health(int new_health) {

		if(new_health <= get_max_health()){
	        health_ = new_health;
		} else {
			health_ = get_max_health();
		}
    }

    int Character::get_max_health() const {
    	return max_health_ + get_inventory()->get_stats_health();
    }

    void Character::set_max_health(int new_max_health) {
        //Unsafe?
		max_health_ = new_max_health;
    }
    int Character::get_strength() const {
        // TODO: Count buff/debuff strength
    	return strength_ + get_inventory()->get_stats_strength();
    }

    std::string Character::get_name_of_attack() const {
    	return name_of_attack_;
    }

    // The character takes an action
    void Character::action() {}

    // The chararacter goes a step in a direction (see Enum)
    void Character::go(int direction) {
    	current_environment_ = get_environment()->get_neighbour(direction);
    }

    Environment * Character::get_environment() {
        return current_environment_;
    }

    void Character::enter(Environment * new_environment) {
    	current_environment_ = new_environment;
    }

    // The character attacks an enemy
    void Character::attack(Character * enemy) {

		int damage = get_environment()->get_effect(get_strength(), get_type());

		std::cout << get_name() << " " << get_name_of_attack() << " " << enemy->get_name() << " for " << damage << " damage" << std::endl;

		int retaliation = enemy->defend(this, damage);
		set_health(get_health() - retaliation);
	}

	//Character takes damage and potentially retaliates
	int Character::defend(Character * from, int damage){
		set_health(get_health() - damage);

		std::cout << get_name() << " has " << get_health() << " health left" << std::endl;

		return 0;
	}

    // The character picks up an Item. Not able to take items if
    // enemy is in the same environment.
    bool Character::take(Item* item) {
        const Inventory* inventory = get_inventory();
        if ( inventory->get_number_of_items() < inventory->get_slot_limit() && inventory->get_weight() + item->get_weight() <= inventory->get_weight_limit() ) {
            inventory_.add_item(item);
            get_environment()->get_container()->remove_item(item);
            return true;
        }
        return false;
    }

    // The character drops an Item
    void Character::drop(Item* item) {
        get_environment()->add_item(item);
        inventory_.remove_item(item);
    }

    // The character talks to another character
    void Character::talk_to(Character) {}

    bool Character::get_aggression() const {
        return aggression_;
    }

    void Character::set_aggression(bool aggression){
        aggression_ = aggression;
    }

    bool Character::is_dead() const {
        return get_health() <= 0;
    }

    Inventory const* Character::get_inventory() const {
        return &inventory_;
    }

	int Character::get_value() const {
		return get_inventory()->get_value();
	}
}

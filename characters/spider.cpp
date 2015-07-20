#include "spider.hpp"

namespace jonsson_league {

	Spider::Spider() : Character() {}

	Spider::Spider(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment)
		: Character(type, name, health, strength, name_of_attack, current_environment) {}

	int Spider::defend(Character * enemy, int damage){
	
		float retaliation_factor = 0.3;

		set_health(get_health() - damage);
    	std::cout << get_name() << " has " << get_health() << " health left" << std::endl;
		std::cout << get_name() << " retaliates with a poisonous bite for " << (int) (damage * retaliation_factor) << " damage!"<< std::endl;

		return damage * retaliation_factor;
	}
}

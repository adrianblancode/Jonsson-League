#include "jonsson.hpp"

namespace jonsson_league {

	Jonsson::Jonsson() : Character() {}

	Jonsson::Jonsson(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment)
		: Character(type, name, health, strength, name_of_attack, current_environment) {}

	void Jonsson::attack(Character * enemy){
		
		int damage = get_environment()->get_effect(get_strength(), get_type());
		
		//Jonsson can hurt himself
		if(damage < 0){
			set_health(get_health() + damage);
			return;
		}

		std::cout << get_name() << " " << get_name_of_attack() << " " << enemy->get_name() << " for " << damage << " damage" << std::endl;
		int retaliation = enemy->defend(this, damage);
		set_health(get_health() - retaliation);
		return;
	}

}

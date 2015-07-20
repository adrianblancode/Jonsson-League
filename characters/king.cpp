#include "king.hpp"

namespace jonsson_league {

	King::King() : Character() {}

	King::King(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment)
		: Character(type, name, health, strength, name_of_attack, current_environment) {}

	void King::say() const {
		std::cout << get_name() << ": ";
		std::cout << "Well, thief! I smell you, I hear your breath, I feel your air. Where are you?" << std::endl;
	}

	void King::attack(Character * enemy){
		
		float damage_factor = 1.0;

		if(get_health() < get_max_health()){
			std::cout << get_name() << ": How dare you wound ME?!" << std::endl;
			std::cout << get_name() << " has gone berserk!" << std::endl;
			damage_factor = 1.7;
		}
		int damage = get_environment()->get_effect(get_strength() * damage_factor, get_type());
		std::cout << get_name() << " " << get_name_of_attack() << " " << enemy->get_name() << " for " << damage << " damage" << std::endl;
		int retaliation = enemy->defend(this, damage);
		set_health(get_health() - retaliation);
		return;
	}

}

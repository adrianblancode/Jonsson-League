#include "throneroom.hpp"

namespace jonsson_league {
	
	Throneroom::Throneroom() : Environment() {}

	Throneroom::Throneroom(std::string description, std::string type)
		: Environment(description, type) {}


	int Throneroom::get_effect(int damage, std::string character_type) {
		float r = (rand()) / (float) (RAND_MAX);
		if(character_type == "Thief" && r <= 0.5){
			std::cout << "You became blinded by all the glistening treasure and hurt yourself in confusion! " << std::endl;
			return -damage;
		}
		return damage;
	}

}

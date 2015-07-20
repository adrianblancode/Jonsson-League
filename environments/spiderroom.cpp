#include "spiderroom.hpp"

namespace jonsson_league {
	
	Spiderroom::Spiderroom() : Environment() {}

	Spiderroom::Spiderroom(std::string description, std::string type)
		: Environment(description, type) {}


	int Spiderroom::get_effect(int damage, std::string character_type) const {
		float r = (rand()) / (float) (RAND_MAX);
		if(character_type != "Spider" && r <= 0.2){
			std::cout << "Your hand got stuck in a spider web. " << std::endl;
			return 0;
		}
		return damage;
	}

}

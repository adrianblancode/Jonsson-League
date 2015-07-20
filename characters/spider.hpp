#ifndef SPIDER_H
#define SPIDER_H

#include "character.hpp"

namespace jonsson_league {

	class Spider : public Character {
	private:
	public:
		Spider();
		Spider(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment);
		virtual int defend(Character *, int);
	};

}

#endif // SPIDER_H

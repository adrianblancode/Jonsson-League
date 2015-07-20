#ifndef JONSSON_H
#define JONSSON_H

#include "character.hpp"

namespace jonsson_league {

	class Jonsson : public Character {
	private:
	public:
		Jonsson();
		Jonsson(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment);
		virtual void attack(Character *);
	};

}

#endif // JONSSON_H

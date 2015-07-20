#ifndef KING_H
#define KING_H

#include "character.hpp"

namespace jonsson_league {

	class King : public Character {
	private:
	public:
		King();
		King(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment);
		virtual void say() const;
		virtual void attack(Character *);
	};

}

#endif // KING_H

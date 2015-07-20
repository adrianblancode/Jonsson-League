#ifndef THRONEROOM_H
#define THRONEROOM_H

#include "../environments/environment.hpp"
#include <cstdlib>

namespace jonsson_league {

	// Contains one single tile of the map
	class Throneroom : public Environment {
	private:
	public:
		Throneroom();
		Throneroom(std::string, std::string);
		virtual int get_effect(int damage, std::string character_type);
	};

}

#endif // THRONEROOM_H

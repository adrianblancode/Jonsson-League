#ifndef SPIDERROOM_H
#define SPIDERROOM_H

#include "../environments/environment.hpp"
#include <cstdlib>

namespace jonsson_league {

	// Contains one single tile of the map
	class Spiderroom : public Environment {
	private:
	public:
		Spiderroom();
		Spiderroom(std::string, std::string);
		virtual int get_effect(int damage, std::string character_type) const;
	};

}

#endif // SPIDERROOM_H

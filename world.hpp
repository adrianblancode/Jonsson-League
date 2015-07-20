#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include "environments/environment.hpp"
#include "environments/spiderroom.hpp"
#include "environments/throneroom.hpp"
#include "characters/character.hpp"
#include "characters/jonsson.hpp"
#include "characters/king.hpp"
#include "characters/spider.hpp"
#include "directions.hpp"
#include "inventory.hpp"

namespace jonsson_league {

	class World {
	private:
		std::vector<std::string> savestate_;
	    Environment * starting_environment_;
	    std::vector<Character *> enemies_;
	    std::vector<Character *> local_enemies_;
	    Character * main_character_;
	    Character * current_character_;
	    bool in_combat_ = false;
	    bool kandelaber_kicked_ = false;
	    std::string room_names_ [10] = {"Entrance", "Spider room", "Dining room", "Kandelaber room", "Fuskbygge", "Catacomb", "Princess room", "Bedroom", "Trophy room", "Throne room"};

		std::map<std::string, Character *> character_map_;
		std::map<std::string, Environment *> environment_map_;
	public:
		World();
		World(std::vector<std::string>);
		~World();
		void init();
		void load();
		bool save(std::string);
		void save_item(std::string, std::ofstream *);

		void print_items(std::vector<Item*> * vec) const;
		void describe_room() const;
		bool describe_inventory(std::string);
		bool player_status(std::string);
	    bool description(std::string);
	    bool move_character(std::string);
	    void collapse_fuskbygge();
	    bool directions(std::string args);
		bool take(std::string args);
		bool drop(std::string args);

		bool eat(std::string args);
		bool kick(std::string args);
		void kick_kandelaber();
	    bool attack(std::string args);
		bool suicide(std::string);
	    void check_status();
	    bool in_combat();
	    bool set_combat_flag(bool);
	    bool resolve_combat(bool aggressive);
	    std::vector<Character * > get_local_enemies() const;
	    void set_local_enemies(std::vector<Character *> *);


	    std::string get_string_from_enum(int num);

	    Character* get_main_character() const;
	    void set_main_character(Character * character);

	    Character* get_current_character() const;
	    void set_current_character(Character * character);

	    Character* get_target(std::string target);
		Character* get_character_by_name(std::string target);
	    Character* get_target_by_name(std::string target);
	    Character* get_next_character() const;

		void default_savestate(std::vector<std::string> *);
		std::vector<std::string> get_savestate();
		void set_savestate(std::vector<std::string>);
		void set_savestate(int, std::string);
		void ss_place_character(Character *, Environment *);
	};

}

#endif // WORLD_H

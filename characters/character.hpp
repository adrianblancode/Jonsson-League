#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "../item.hpp"
#include "../environments/environment.hpp"
#include "../inventory.hpp"
#include "../directions.hpp"
#include <iostream>

namespace jonsson_league {

	// Base class for all characters, and NPCs
	class Character {
	private:
		std::string type_;
		std::string name_;
		std::string name_of_attack_;
		int weight_;
		int health_;
		int max_health_;
		int strength_;
		bool aggression_;
		Environment * current_environment_;
		Inventory inventory_;
	public:
		Character();

		Character(std::string type, std::string name, int health, int strength, std::string name_of_attack, Environment * current_environment);

		virtual ~Character();

		virtual void say() const;

		// Returns what type the character is eg Ogre
		std::string get_type() const;

		// Returns the name of the character eg Gandalf
		std::string get_name() const;

		/**
		 * Returns the total weight of the character, including the 
		 * weight of the inventory. 
		 */
		int get_weight() const;

		int get_base_weight() const;

		void set_base_weight(int);

		// Returns the HP of the character
		int get_health() const;

		// Sets the HP of the character
		void set_health(int new_health);

		// Returns the max HP of the character
		int get_max_health() const;

		// Sets the max HP of the character
		void set_max_health(int new_health);
		
		// Returns the strength of the 
		int get_strength() const;

		// Returns the name of the attack that this character has
		std::string get_name_of_attack() const;

		void action();
		void go(int);
		Environment * get_environment();
		void enter(Environment *);
		
		virtual void attack(Character *);
		virtual int defend(Character *, int);
		
		bool take(Item*);
		void drop(Item*);
		void talk_to(Character);
		bool get_aggression() const;
		void set_aggression(bool);
		bool is_dead() const;
		void add_inventory(Inventory* inventory);
		Inventory const* get_inventory() const;
		int get_value() const;
	};

}

#endif // CHARACTER_H

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <string>

#include "../item.hpp"
#include "../container.hpp"

namespace jonsson_league {

	class Environment{
	private:
		// std::vector<Item*> * items_;
		std::vector<Environment *> * neighbours_;
		std::string description_;
		std::string type_;
		Container* container_;
	public:
	    Environment();
		Environment(std::string, std::string);
	    Environment(Container* container, std::vector<Environment*> * neighbours, std::string description, std::string type);
	    virtual ~Environment();
		Container * get_container() const;
		void add_item(Item *);
		std::string get_type() const;
		std::string get_description() const;
		void set_description(std::string);
		std::vector<Environment *> * get_neighbours() const;
		Environment * get_neighbour(int) const;
		bool set_neighbour(int, Environment *);
		virtual int get_effect(int, std::string character_type) const;
	};
}

#endif // ENVIRONMENT_H

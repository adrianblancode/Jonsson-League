#include "environment.hpp"

namespace jonsson_league {

    Environment::Environment() {
        description_ = "unknown";
        type_ = "unknown";
		neighbours_ = new std::vector<Environment * >(4, NULL);
		container_ = new Container();
    }

	Environment::Environment(std::string description, std::string type){
		description_ = description;
		type_ = type;
		neighbours_ = new std::vector<Environment * >(4, NULL);
		container_ = new Container();
	}

    Environment::Environment(Container* container, std::vector<Environment*> * neighbours, std::string description, std::string type){

        //OBS! Shared pointers?
        neighbours_ = neighbours;
        description_ = description;
        type_ = type;
        container_ = container;
    }

    Environment::~Environment() {
    	delete neighbours_;
    	delete container_;
    }

    Container * Environment::get_container() const {
    	return container_;
    }

	void Environment::add_item(Item * item){
		container_->add_item(item);
	}
    
	std::string Environment::get_type() const {
    	return type_;
    }

    // Returns a description of the environment
    std::string Environment::get_description() const {
    	return description_;
    }
	
	void Environment::set_description(std::string description){
		description_ = description;
	}

	//Returns a vector of environment pointers which are the neighbours at specified directions
    std::vector<Environment *> * Environment::get_neighbours() const {
    	return neighbours_;
    }

	Environment * Environment::get_neighbour(int index) const {
		if(index < 0 || index >= (int) get_neighbours()->size()){
			return NULL;
		} else {
			return (*neighbours_)[index];
		} 
	}

	//Sets the neighbour for the specified direction
	bool Environment::set_neighbour(int index, Environment * nb) {

		if(index < 0 || index >= (int) get_neighbours()->size()){
			return false;
		}

		(*neighbours_)[index] = nb;

		return true;
	}

	int Environment::get_effect(int damage, std::string character_type) const {
		return damage;
	}
}

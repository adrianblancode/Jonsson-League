// projektlokala headerfiler
#include "character.hpp"

// STL headerfiler
#include <iostream>
#include <sstream>              // std::stringstream
#include <assert.h>             // assert(b) ger felmeddelande om b falsk


int main()
{
using namespace jonsson_league;        // Exponera funktionalitet i namnrymden lab2

std::cout << "----------------------------------------" << std::endl;
std::cout << "Initiating tests" << std::endl;

{
    std::cout << "Testing default constructor" << std::endl;
    Character character;
    assert(character.get_type() == "unknown");
    assert(character.get_name() == "unknown");
    assert(character.get_name_of_attack() == "attacks");
    assert(character.get_weight() == 1);
    assert(character.get_health() == 1);
    assert(character.get_max_health() == 1);
    assert(character.get_strength() == 1);
    assert(character.get_aggression() == false);
}

{
    std::cout << "Testing custom constructor" << std::endl;
    Environment* environment = new Environment();
    Character character("Type", "Name", 20, 30, "Attack", environment);
    assert(character.get_type() == "Type");
    assert(character.get_name() == "Name");
    assert(character.get_name_of_attack() == "Attack");
    assert(character.get_weight() == 10);
    assert(character.get_health() == 20);
    assert(character.get_max_health() == 20);
    assert(character.get_strength() == 30);
    assert(character.get_aggression() == false);
}

{
    std::cout << "Testing set_max_health and get_max_health" << std::endl;
    Character character;
    character.set_max_health(10);
    assert(character.get_max_health() == 10);
    character.set_max_health(100);
    assert(character.get_max_health() == 100);
}

{
    std::cout << "Testing set_health and get_health" << std::endl;
    Character character;
    character.set_max_health(1000);
    character.set_health(10);
    assert(character.get_health() == 10);
    character.set_health(100);
    assert(character.get_health() == 100);
}

{
    std::cout << "Testing get_weight" << std::endl;
    Environment * entrance = new Environment("A very dark room, you hear the faint sounds of nerds typing.", "Starting area");
    // Weight 10
    Character character("a", "b", 1, 1, "c", entrance);
    // Weight 1
    Item* sword = new Item("Svärdet Sivert", "A legendary sword, forged by blacksmith Yggrimmar.", 1, 100, 10, 0);
    entrance->add_item(sword);
    // Before carrying sword in inventory
    assert(character.get_weight() == 10);
    // Adding sword to inventory
    character.take(sword);
    // When carrying sword in inventory should be 10+1 = 11
    assert(character.get_weight() == 11);
}

{
    std::cout << "Testing take and drop item" << std::endl;
    Environment * entrance = new Environment("A very dark room, you hear the faint sounds of nerds typing.", "Starting area");
    entrance->get_container()->set_slot_limit(2);
    entrance->get_container()->set_weight_limit(2);
    Character character("a", "b", 1, 1, "c", entrance);
    Item* sword = new Item("Svärdet Sivert", "A legendary sword, forged by blacksmith Yggrimmar.", 1, 100, 10, 0);
    Item* knife = new Item("Kniven Ken", "A legendary knife, forged by blacksmith Hjalmar.", 1, 10, 1, 0);
    entrance->add_item(sword);
    entrance->add_item(knife);

    assert(entrance->get_container()->get_number_of_items() == 2);
    assert(character.get_inventory()->get_number_of_items() == 0);

    character.take(sword);

    assert(entrance->get_container()->get_number_of_items() == 1);
    assert(character.get_inventory()->get_number_of_items() == 1);
    assert(character.get_inventory()->get_items()->at(0)->get_name() == "Svärdet Sivert");
}


std::cout << "All tests passed!" << std::endl;
std::cout << "----------------------------------------" << std::endl;

return 0;
}


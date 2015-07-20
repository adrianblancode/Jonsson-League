// projektlokala headerfiler
#include "king.hpp"

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
    King king;
    assert(king.get_type() == "unknown");
    assert(king.get_name() == "unknown");
    assert(king.get_name_of_attack() == "attacks");
    assert(king.get_weight() == 1);
    assert(king.get_health() == 1);
    assert(king.get_max_health() == 1);
    assert(king.get_strength() == 1);
    assert(king.get_aggression() == false);
}

{
    std::cout << "Testing custom constructor" << std::endl;
    Environment* environment = new Environment();
    King king("Type", "Name", 20, 30, "Attack", environment);
    assert(king.get_type() == "Type");
    assert(king.get_name() == "Name");
    assert(king.get_name_of_attack() == "Attack");
    assert(king.get_weight() == 10);
    assert(king.get_health() == 20);
    assert(king.get_max_health() == 20);
    assert(king.get_strength() == 30);
    assert(king.get_aggression() == false);
}


std::cout << "All tests passed!" << std::endl;
std::cout << "----------------------------------------" << std::endl;

return 0;
}


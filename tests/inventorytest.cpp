// projektlokala headerfiler
#include "inventory.hpp"

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
    std::cout << "Testing get_stats_health" << std::endl;
    Inventory inventory;
    assert(inventory.get_stats_health() == 0);
    Item* item = new Item("a", "b", 1, 1, 10, 1);
    assert(inventory.add_item(item) == true);
    assert(inventory.get_stats_health() == 10);
}

{
    std::cout << "Testing get_stats_strength" << std::endl;
    Inventory inventory;
    assert(inventory.get_stats_strength() == 0);
    Item* item = new Item("a", "b", 1, 1, 1, 10);
    assert(inventory.add_item(item) == true);
    assert(inventory.get_stats_strength() == 10);
}

std::cout << "All tests passed!" << std::endl;
std::cout << "----------------------------------------" << std::endl;

return 0;
}


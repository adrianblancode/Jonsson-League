// projektlokala headerfiler
#include "container.hpp"

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
    Container container;
    assert(container.get_slot_limit() == 10);
    assert(container.get_weight_limit() == 10);
}

{
    std::cout << "Testing (int num_slots, int max_weight) constructor" << std::endl;
    Container container(3,4);
    assert(container.get_slot_limit() == 3);
    assert(container.get_weight_limit() == 4);
}

{
    std::cout << "Testing contains" << std::endl;
    Container container;
    Item* item = new Item();
    assert(container.contains(item) == false);
    container.add_item(item);
    assert(container.contains(item) == true);
}

{
    std::cout << "Testing get_number_of_items" << std::endl;
    Container container(2,2);
    assert(container.get_number_of_items() == 0);
    Item* a = new Item();
    Item* b = new Item();
    container.add_item(a);
    assert(container.get_number_of_items() == 1);
    container.add_item(b);
    assert(container.get_number_of_items() == 2);
}

{
    std::cout << "Testing get_slot_limit" << std::endl;
    Container container;
    assert(container.get_slot_limit() == 10);
}

{
    std::cout << "Testing set_slot_limit" << std::endl;
    Container container;
    assert(container.get_slot_limit() == 10);
    container.set_slot_limit(30);
    assert(container.get_slot_limit() == 30);
}

{
    std::cout << "Testing get_weight_limit" << std::endl;
    Container container;
    assert(container.get_weight_limit() == 10);
}

{
    std::cout << "Testing set_weight_limit" << std::endl;
    Container container;
    assert(container.get_weight_limit() == 10);
    container.set_weight_limit(30);
    assert(container.get_weight_limit() == 30);
}

{
    std::cout << "Testing get_weight" << std::endl;
    Container container(1000, 1000);
    assert(container.get_weight() == 0);
    Item* item = new Item("a", "b", 10, 1, 0, 0);
    container.add_item(item);
    assert(container.get_weight() == 10);
}

{
    std::cout << "Testing add_item" << std::endl;
    Container container(2,2);
    Item* item = new Item("It1", "An item1", 1, 1, 0, 0);
    Item* item2 = new Item("It2", "An item2", 1, 1, 0, 0);
    Item* item3 = new Item("It3", "An item3", 1, 1, 0, 0);
    assert(container.get_number_of_items() == 0);
    assert(container.add_item(item) == true);
    assert(container.get_number_of_items() == 1);
    assert(container.add_item(item2) == true);
    assert(container.get_number_of_items() == 2);
    // Container full - should not add new item
    assert(container.add_item(item3) == false);
    assert(container.get_number_of_items() == 2);
}

{
    std::cout << "Testing remove_item" << std::endl;
    Container container(2,2);
    Item* item1 = new Item("It1", "An item1", 1, 1, 0, 0);
    Item* item2 = new Item("It2", "An item2", 1, 1, 0, 0);
    Item* item3 = new Item("It3", "An item3", 1, 1, 0, 0);
    assert(container.get_number_of_items() == 0);
    assert(container.add_item(item1) == true);
    assert(container.get_number_of_items() == 1);
    assert(container.remove_item(item1) == true);
    // Item 3 not added, should hence not work to remove.
    assert(container.remove_item(item3) == false);
    assert(container.get_number_of_items() == 0);
    assert(container.add_item(item2) == true);
    assert(container.get_number_of_items() == 1);
    assert(container.add_item(item3) == true);
    assert(container.get_number_of_items() == 2);
    assert(container.remove_item(item2) == true);
    assert(container.remove_item(item3) == true);
    assert(container.remove_item(item1) == false);
    assert(container.remove_item(item2) == false);
    assert(container.remove_item(item3) == false);
}

{
    std::cout << "Testing get_items" << std::endl;
    Container container(2,2);
    Item* item = new Item("It1", "An item1", 1, 1, 0, 0);
    Item* item2 = new Item("It2", "An item2", 1, 1, 0, 0);
    assert(container.get_number_of_items() == 0);
    assert(container.add_item(item) == true);
    assert(container.get_number_of_items() == 1);
    assert(container.add_item(item2) == true);
    assert(container.get_number_of_items() == 2);

    std::vector<Item*> * items = container.get_items();
    assert(items->at(0)->get_name() == "It1");
    assert(items->at(1)->get_name() == "It2");
}

{
    std::cout << "Testing get_item_by_name" << std::endl;
    Container container(2,2);
    Item* item = new Item("It1", "An item1", 1, 1, 0, 0);
    assert(container.add_item(item) == true);
    // MUST BE UPPER CASE
    assert(container.get_item_by_name("IT1") != NULL);
    assert(container.get_item_by_name("IT2") == NULL);
}

std::cout << "All tests passed!" << std::endl;
std::cout << "----------------------------------------" << std::endl;

return 0;
}


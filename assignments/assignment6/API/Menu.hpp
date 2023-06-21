// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Menu

Constructor:
default

Feilds:
l_dish : Dish[]
l_instock : Dish[]

Functions:
all_instock() : void - puts all Dishes in l_dish into l_instock
rm_instock(int) : void - removes a Dish l_instock that is in l_dish using Dish id
add_instock(int) : void - addes a Dish l_instock that is in l_dish using Dish id
add_dish(char*, double, char*, char**) : void - creates and adds a Dish to to l_dish
rm_dish(int) : void - removes Dish from l_dish searches by Dish id
get_instock() : Dish* - returns the list of Dishes that are in stock
*/
#include "Dish.hpp"

class Menu {
    public:
        void all_instock();
        void rm_instock(int);
        void add_instock(int);
        void add_dish(char*, double, char*, char**);
        void rm_dish(int);
        Dish* get_instock() const;
    private:
        Dish l_dish[100]; // can have a max of 100 dishes pre menu
        Dish l_instock[100];
};
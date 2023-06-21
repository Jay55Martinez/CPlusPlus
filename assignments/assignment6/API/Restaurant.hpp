// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Restaurant

Constructor: 
Restaurant() : non default 

Feilds: 
name : char*
open : bool
address : Address
menu : Menu
id : int
l_order : vector<Order>

Functions:
set_name() : void
set_open() : void
set_address() : void
init_menu() : void
init_id() : void
update_menu(int, int) : void - allows from removing/adding of dishes or setting what is avalible
change_status(int order_num, Status) : void
get_menu() : Menu
get_item(int) : Dish
get_id() : int
*/
#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Menu.hpp"
#include "Address.hpp"
#include "Status.hpp"
#include "Order.hpp"
#include <vector>

class Order;

class Restaurant {
public:
    Restaurant(); // non-default constructor
    void set_name();
    void set_open();
    void set_address();
    void init_menu();
    void init_id();
    void update_menu(int, int);
    void change_status(int, Status);
    Menu get_menu() const;
    Dish get_item(int) const;
    int get_id() const;

private:
    char name[17]; // length of the restaurant name can't be more than 16 characters (+1 for null-terminator)
    bool open;
    Address address;
    Menu menu;
    int id;
    std::vector<Order> l_order;
};

#endif // RESTAURANT_HPP

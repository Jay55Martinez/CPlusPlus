// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Selector:

Constructor: 
Selector(User, Restaurant[])

Feilds:
restaurants : Restaurant**
cart : Cart*
user : User*

Functions:
add_dish_to_cart(int restaurant_id, int dish_id) : void
add_dish_to_favorite(int, int) : void
rm_dish_from_cart(int, int) : void
rm_dish_from_favorite(int, int) : void
create_order() : void
*/
#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "Restaurant.hpp"
#include "Cart.hpp"
#include "User.hpp"
#include "Order.hpp"

class Restaurant;
class Cart;

class Selector {
public:
    Selector(User, Restaurant[]); // Constructor
    void add_dish_to_cart(int, int);
    void add_dish_to_favorite(int, int);
    void rm_dish_from_cart(int, int);
    void rm_dish_from_favorite(int, int);
    void create_order();

private:
    Restaurant** restaurants; // Use a pointer to a pointer
    Cart* cart;
    User* user;
};

#endif // SELECTOR_HPP

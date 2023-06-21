// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class User:

Constructor:
default

Feilds:
password : char*
username : char*
creditcard_num : char*
order_history : vector<Order>
address : Address
l_favorite : vector<pair<int,vector<int>>>

Functions:
set_password() : void
set_username() : void
set_creditcard_num() : void
add_order(Order) : void
set_address() : void
add_favorite(int restaurant_id, int dish_id) : void
get_order_history() : vector<Order>
get_favorite() : vector<pair<int,vector<int>>>
*/
#ifndef USER_HPP
#define USER_HPP

#include "Order.hpp"
#include "Address.hpp"
#include <vector>
#include <utility>

class Order;

class User {
public:
    void set_password();
    void set_username();
    void set_creditcard_num();
    void add_order(Order);
    void set_address();
    void add_favorite(int, int);
    std::vector<Order> get_order_history() const;
    std::vector<std::pair<int, std::vector<int>>> get_favorite() const;

private:
    char password[17]; // length of the password can't be more than 16 characters (+1 for null-terminator)
    char username[11]; // length of the username can't be more than 10 characters (+1 for null-terminator)
    char creditcard_num[13]; // length of the credit card number can't be more than 12 characters (+1 for null-terminator)
    std::vector<Order> order_history;
    Address address;
    std::vector<std::pair<int, std::vector<int>>> l_favorite;
};

#endif // USER_HPP

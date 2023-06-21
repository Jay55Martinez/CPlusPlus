// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Order: 

Constructor:
Order(vector<int>, User*, Restaurant*)

Feilds:
user : User*
restaurant : Restaurant*
l_dish_id : vector<int>
status : Status

Functions:
update_status(Status) : void
get_dishes() : vector<int>
*/
#ifndef ORDER_HPP
#define ORDER_HPP

#include "Restaurant.hpp"
#include "User.hpp"
#include "Status.hpp"
#include <vector>

class User;
class Restaurant; // Forward declaration of Restaurant class

class Order {
public:
    Order(std::vector<int>, User*, Restaurant*); // Constructor
    void update_status(Status);
    std::vector<int> get_dishes() const;

private:
    User* user;
    Restaurant* restaurant; // Use a pointer to Restaurant
    std::vector<int> l_dish_id;
    Status status;
};

#endif // ORDER_HPP

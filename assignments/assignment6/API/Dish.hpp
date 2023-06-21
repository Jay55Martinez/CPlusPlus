// Jay Martinez -- Assignment 6 -- 6/19/23
/*
Class Dish:

Constructor:
Dish(char*, double, char*, char**)

Fields:
name : char*
price : double
description : char*
allergires : char**
id : int

Functions: 
get_name() : char*
get_price() : double
get_description : char*
get_id() : int
contains_allergy(char*) : bool
init_id() : void
operator==(int) : bool - takes in a dish ID and returns true if the Dish has the same
*/
#ifndef DISH_HPP
#define DISH_HPP

class Dish {
public:
    Dish(char*, double, char*, char**); // constructor
    char* get_name() const;
    char* get_description() const;
    double get_price() const;
    int get_id() const;
    bool contains_allergy(char* allergy) const;
    void init_id();
    bool operator==(Dish&);

private:
    char name[16]; // length of the dish name can't be more than 15 characters (+1 for null-terminator)
    double price;
    char description[101]; // length of the description can't be more than 100 characters (+1 for null-terminator)
    char** allergies;
    int id;
};

#endif // DISH_HPP

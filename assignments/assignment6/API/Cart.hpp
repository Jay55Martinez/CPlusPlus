// Jay Martinez -- Assignment 6 -- 6/19/23
/*
class Cart:

Constructor: 
default

Feilds:
cart : vector<pair<int,vector<int>>>

Functions:
add_to_cart(int restaurant_id,  int dish_id) : void
rm_from_cart(int restaurant_id,  int dish_id) : void
get_total_cost() : double
get_car() : vector<pair<int,vector<int>>>
*/
#include <vector>
#include <utility>

class Cart {
    public:
        void add_to_cart(int, int);
        void rm_from_cart(int, int);
        double get_total_cost() const;
        std::vector<std::pair<int,std::vector<int>>> get_cart() const;
    private:
        std::vector<std::pair<int,std::vector<int>>> cart;
};
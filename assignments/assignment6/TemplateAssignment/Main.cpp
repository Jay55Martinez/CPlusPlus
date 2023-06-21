// Jay Martinez -- assignment 6 -- 6/20/23
#include "Repository.cpp"
#include "Book.cpp"
#include "Song.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout<<"new Repository int:"<<endl;
    Repository<int> ri;
    ri.add_item(12);
    ri.add_item(42);
    ri.add_item(21);
    ri.add_item(1);
    ri.add_item(12);
    Repository<int> ri2 = ri; // copy assignment
    cout<<"position of 21: "<<to_string(ri2.get_position(21))<<endl;

    cout<<"new Repository Book:"<<endl;
    Repository<Book> rb;
    rb.add_item(Book("The Road", "Cormac McCarthy", 2006));
    rb.add_item(Book("Harry Potter", "J. K. Rowling", 2002));
    rb.add_item(Book("Best Book", "Jay Martinez", 2023));
    rb.rm_item(Book("The Road", "Cormac McCarthy", 2006));
    Repository<Book> rb2(rb); // copy construtor
    cout<<"size: "<<to_string(rb2.get_size())<<endl;

    cout<<"new Repository string"<<endl;
    Repository<string> rs;
    rs.add_item(vector<string>{"hello", "hi", "hola", "bye", "hi"});
    rs.rm_item(vector<string>{"bye", "goodbye"});
    Repository<string> rs2 = std::move(rs); // move assignment
    cout<<"size: "<<to_string(rs2.get_size())<<endl;

    cout<<"new Repository Song: "<<endl;
    Repository<Song> rsong;
    rsong.add_item(vector<Song>{Song("Humble", "Kendrick Lemar", 2019, 3.13), Song("Humble", "Kendrick Lemar", 2019, 3.13)});
    Repository<Song> rsong2(std::move(rsong)); // move constructor
    cout<<"size: "<<to_string(rsong2.get_size())<<endl;
    return 0;
}
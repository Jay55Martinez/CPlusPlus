// Jay Martinez -- Activity6 -- 5/26/23
#include <iostream>
#include <cstring>
using namespace std;

struct planet {
    char* planet_name = new char(10); // allocate in memory
    double planet_distance;
    struct {
        char galaxy_system [ 13 ];
        double mass;
    } facts, *facts_ptr = &facts;
} planet_record, *planet_ptr = &planet_record, all_records[5];

planet earth;
planet mars;
planet sun;
planet jupiter;
planet moon;


int main() {
    // initializing member values for planet_record
    strcpy(planet_record.planet_name, "Earth"); 
    planet_record.planet_distance = 1.0;
    strcpy(planet_record.facts.galaxy_system, "Milky Way");
    planet_record.facts.mass = 15000.23;

    /*
    a)
    cout<<planet_record.planet_name<<endl;
    b)
    cout<<planet_ptr->planet_name<<endl;
    c)
    cout<<planet_record.planet_distance<<endl;
    d)
    cout<<planet_ptr->planet_distance<<endl;
    e)
    cout<<planet_record.facts.mass<<endl;
    f)
    cout<<planet_ptr->facts_ptr->mass<<endl;
    g)
    cout<<planet_record.facts.galaxy_system<<endl;
    h)
    cout<<planet_ptr->facts_ptr->galaxy_system<<endl;
    */
    // a and b only work if planet_name is defined because without defining there is no
    // memory location for the cstring causing a segmentation error

    // 2) code worked with no syntax errors
    cout<<planet_record.planet_name<<endl; 
    cout<<planet_ptr->planet_name<<endl;
    cout<<planet_record.planet_distance<<endl;
    cout<<planet_ptr->planet_distance<<endl;
    cout<<planet_record.facts.mass<<endl;
    cout<<planet_ptr->facts_ptr->mass<<endl;
    cout<<planet_record.facts.galaxy_system<<endl;
    cout<<planet_ptr->facts_ptr->galaxy_system<<endl;
    cout<<endl;
    // 3a)
    // initializing member values for earth
    strcpy(earth.planet_name, "Earth");
    earth.planet_distance = 1.0;
    strcpy(earth.facts.galaxy_system, "Milky Way");
    earth.facts.mass = 15000.23;

    // initializing member values for mars
    strcpy(mars.planet_name, "Mars");
    mars.planet_distance = 1500.0;
    strcpy(mars.facts.galaxy_system, "Milky Way");
    mars.facts.mass = 20000.43;

    // initializing member values for sun
    strcpy(sun.planet_name, "Sun");
    sun.planet_distance = 2000.0;
    strcpy(sun.facts.galaxy_system, "Milky Way");
    sun.facts.mass = 22300.43;

    // initializing member values for jupiter
    strcpy(jupiter.planet_name, "Jupiter");
    jupiter.planet_distance = 3500.4;
    strcpy(jupiter.facts.galaxy_system, "Milky Way");
    jupiter.facts.mass = 50000.33;

    // initializing member values for moon
    strcpy(moon.planet_name, "Moon");
    moon.planet_distance = 1000.0;
    strcpy(moon.facts.galaxy_system, "Milky Way");
    moon.facts.mass = 13000.67;

    // store 5 planets in all_records
    all_records[0] = earth;
    all_records[1] = mars;
    all_records[2] = sun;
    all_records[3] = jupiter;
    all_records[4] = moon;

    for(int i=0; i<5; i++) {
        cout<<"Planet "<<i+1<<":"<<endl;
        cout<<all_records[i].planet_name<<endl;
        cout<<all_records[i].planet_distance<<endl;
        cout<<all_records[i].facts.galaxy_system<<endl;
        cout<<all_records[i].facts.mass<<endl<<endl;
    }

    // 3b)
    // pointer dynamically allocated array of of 5 planets
    planet* ptrs_all_records = (planet*) malloc(5 * sizeof(planet));
    ptrs_all_records[0] = all_records[0];
    ptrs_all_records[1] = all_records[1];
    ptrs_all_records[2] = all_records[2];
    ptrs_all_records[3] = all_records[3];
    ptrs_all_records[4] = all_records[4];

    // prints the pointers data
    for(int i=0; i<5; i++) {
        cout<<"Planetptr "<<i+1<<":"<<endl;
        cout<<(ptrs_all_records + i)->planet_name<<endl;
        cout<<(ptrs_all_records + i)->planet_distance<<endl;
        cout<<(ptrs_all_records + i)->facts.galaxy_system<<endl;
        cout<<(ptrs_all_records + i)->facts.mass<<endl<<endl;
    }

    // freeing space on heap
    free(ptrs_all_records);

    return 0;
}
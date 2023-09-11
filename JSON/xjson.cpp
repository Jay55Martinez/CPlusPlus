// Jay Martinez & Daneil Na 
// 9/11/23 -- Software Develement CS4500-F23
// xjson program
// Input a json file path and name
// Outputs list of strings and numbers contained in the json file 
#include <iostream>
#include <fstream>

// json library || JSON For Modern C++ || source https://github.com/nlohmann/json
#include "json.hpp"
using json = nlohmann::json;

// recursive function that extracts strings and numbers from a given json file
void extractStrings(const json& j) {
    if (j.is_number()) {
        std::cout << "number ";
    }
    else if (j.is_string()) {
        std::cout << j.get<std::string>() << " ";
    } 
    else if (j.is_object() || j.is_array()) {
        for (const auto& element : j) {
            extractStrings(element);
        }
    }
}

int main(int argc, char** argv) {
    // gets file from command line argument
    std::ifstream jsonFile(argv[1]);

    // checks if file can be opened
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return 1;
    }

    try {

        json jsonData;
        // creates a json object form an ifstream 
        jsonFile >> jsonData;

        // **Function call**
        extractStrings(jsonData);

        std::cout << std::endl;

    } catch (const json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
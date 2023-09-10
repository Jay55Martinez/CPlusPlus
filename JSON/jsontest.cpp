#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

void extractStrings(const json& j) {
    if (j.is_number()) {
        std::cout << "number: " << j.get<int>() << " ";
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

void loopExtract(const json& j) {
    for (const auto& element : j) {
        if (j.is_number()) {
            std::cout << "number: " << j.get<int>() << " ";
        }
        else if (j.is_string()) {
            std::cout << j.get<std::string>() << " ";
        } 
    }
}

int main() {
    std::ifstream jsonFile("your_json_file.json");
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return 1;
    }

    try {
        json jsonData;
        // creates a json object form an ifstream 
        jsonFile >> jsonData;

        // calls a recursive function that gets all of the strings from the json file
        extractStrings(jsonData);
        // loopExtract(jsonData); 

    } catch (const json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
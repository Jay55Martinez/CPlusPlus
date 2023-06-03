// Jay Martinez -- Activity 9 -- 6/2/23
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const void print_items(map<string, vector<map<string, double>>> stores_p) {
    // Calculate the maximum width for each column
    size_t maxNameWidth = 0;
    map<string, size_t> maxPriceWidths;
    for(const auto& store : stores_p) {
        maxNameWidth = max(maxNameWidth, store.first.length());
        for(const auto& item : store.second) {
            for(const auto& entry : item) {
                maxPriceWidths[entry.first] = max(maxPriceWidths[entry.first], to_string(entry.second).length());
            }
        }
    }

    cout<<"Names\t";
    for (const auto& store : stores_p) {
        cout<<store.first<<" ";
    }
    cout<<endl;

    // Iterate over each item
    for (const auto& store : stores_p.begin()->second) {
        for (const auto& item : store) {
            cout<<left<<item.first<<"\t";
            
            // Print the prices under each store
            for (const auto& store : stores_p) {
                bool itemFound = false;
                for (const auto& entry : store.second) {
                    if (entry.find(item.first)!=entry.end()) {
                        cout<<entry.at(item.first)<<"\t";
                        itemFound = true;
                        break;
                    }
                }
                if (!itemFound) {
                    cout<<"-\t";
                }
            }
            cout<<endl;
        }
    }
}

void print_store_items(const map<string, vector<map<string, double>>>& stores_p, const string& store_name) {
    // Find the store with the given name
    cout<<store_name<<endl;
    auto store_it = stores_p.find(store_name);
    if(store_it == stores_p.end()) {
        throw runtime_error("Store not found");
    }

    // Print the items and prices for the specified store
    const vector<map<string, double>>& items = store_it->second;

    for(const map<string, double>& item : items) {
        for(const auto& entry : item) {
            cout<<entry.first<<"\t"<<entry.second<<endl;
        }
    }
}

void average(const map<string, vector<map<string, double>>>& stores_p) {
    cout<<"Average prices: "<<endl;
    map<string, double> average_prices;

    //average price for each item
    for (const auto& store : stores_p) {
        for (const auto& item : store.second) {
            for (const auto& entry : item) {
                average_prices[entry.first] += entry.second;
            }
        }
    }

    // calculates the average
    for (auto& entry : average_prices) {
        entry.second /= stores_p.size();
    }

    // ascending order of the average cost
    vector<pair<string, double>> sorted_prices(average_prices.begin(), average_prices.end());
    sort(sorted_prices.begin(), sorted_prices.end(),
        [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second < b.second;
        });

    // display
    for (const auto& entry : sorted_prices) {
        cout<<entry.first<<" "<<entry.second<<endl;
    }
}

void best_prices(const map<string, vector<map<string, double>>>& stores_p) {
    cout<<"Best prices: "<<endl;
    map<string, pair<string, double>> best_prices;

    // Find the best price for each item
    for (const auto& store : stores_p) {
        for (const auto& item : store.second) {
            for (const auto& entry : item) {
                const string& item_name = entry.first;
                double price = entry.second;
                if (best_prices.find(item_name) == best_prices.end() || price < best_prices[item_name].second) {
                    best_prices[item_name] = make_pair(store.first, price);
                }
            }
        }
    }

    for (const auto& entry : best_prices) {
        cout<<entry.first<<" Store: "<<entry.second.first<<" Price: "<<entry.second.second<<endl;
    }
}

int main() {
    map<string, vector<map<string, double>>> stores_prices;
    // initializing the stores items and prices
    stores_prices["Best Buy"] = { {{"Iphone", 250.82}}, {{"IPad", 70.32}}, {{"XBox", 670.34}}, {{"TV", 690.42}}, {{"GameBoy", 30.23}} };
    stores_prices["Target"] = { {{"Iphone", 230.25}}, {{"IPad", 69.32}}, {{"XBox", 750.67}}, {{"TV", 750.62}}, {{"GameBoy", 60.37}} };
    stores_prices["Amazon"] = { {{"Iphone", 240.56}}, {{"IPad", 240.52}}, {{"XBox", 270.34}}, {{"TV", 666.42}}, {{"GameBoy", 40.23}} };
    stores_prices["Game Stop"] = { {{"Iphone", 230.42}}, {{"IPad", 30.32}}, {{"XBox", 333.34}}, {{"TV", 224.42}}, {{"GameBoy", 90.23}} };
    stores_prices["Walmart"] = { {{"Iphone", 150.82}}, {{"IPad", 340.32}}, {{"XBox", 570.34}}, {{"TV", 590.42}}, {{"GameBoy", 10.23}} };
    
    // Print statements
    print_items(stores_prices);

    cout<<endl;

    try {
        print_store_items(stores_prices, "Best Buy");
        cout<<endl;
        print_store_items(stores_prices, "Target");
    } catch(exception& e) {
        cout<<e.what()<<endl;
    }

    cout<<endl;

    average(stores_prices);

    cout<<endl;

    best_prices(stores_prices);

    return 0;
}
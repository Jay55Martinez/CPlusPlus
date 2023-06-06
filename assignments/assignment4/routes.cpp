// Jay Martinez -- Assignment 4 -- 6/4/23
#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <string>
#include <queue>
using namespace std;

class Distance {
	public:
	Distance(string city, int dist) { target = city; distance = dist;}

	string getTarget() {
		return target;
	}

	int getDistance() {
		return distance;
	}

	int compare (Distance other) {
		return distance - other.distance; 
	}

	bool operator<(const Distance& other) const {
        return distance < other.distance;
    }

	private:
	string target;
	int distance;
};

class Routes {
	public:
	// instantiate class variables
	Routes(string fileName) {		
		inputFile = fileName;
	}

	// read map.txt to populate routeMap
	void populateFiles() {
        ifstream map_file(inputFile);
        if (!map_file.is_open()) {
            throw invalid_argument("File does not exist");
        }
        else {
            string route_info;
            while (getline(map_file, route_info)) {
                string from, to;
                int dist;
                size_t start = 0;
                size_t end = route_info.find(" ");

                if (end != string::npos) {
                    from = route_info.substr(start, end - start); // starting point
                    start = end + 1;
                    end = route_info.find(" ", start);
                    if (end != string::npos) {
                        to = route_info.substr(start, end - start); // ending point
                        start = end + 1;
                        dist = stoi(route_info.substr(start)); // distance int

                        Distance new_dist(to, dist);

                        if (routeMap.find(from) == routeMap.end()) {
                            // 'from' does not exist in the routeMap, create a new set with new_dist
                            set<Distance> set_dist{ new_dist };
                            routeMap[from] = set_dist;
                        }
                        else {
                            // 'from' already exists in the routeMap, append new_dist to its set
                            routeMap[from].insert(new_dist);
                        }
                    }
                }
            }
			for(auto& route : routeMap) {
				cout<<route.first<<": ";
				for(Distance dest : route.second) {
					cout<<dest.getTarget()<<" "<<dest.getDistance()<<", ";
				}
				cout<<endl;
			}
            map_file.close();
        }
    }

	// implement the algorithm using priority queue  
	//Map<string, Integer> shortestKnownDistance = new Map<string,Integer>();
	map<string, int> findShortestKnownDistance() {
    // Create a copy of routeMap to track visited cities
    map<string, set<Distance>> temp = routeMap;

    // Initialize variables
    map<string, int> shortestDist;
    string startingPoint = temp.begin()->first;
    int currentDistance = 0;
    priority_queue<Distance> pq;
    shortestDist[startingPoint] = currentDistance; // Set the starting point to 0

    // Load the queue with all the connecting routes from the starting point
    for (const auto& dist : temp[startingPoint]) {
        pq.push(dist);
    }

    while (!pq.empty()) {
        Distance current = pq.top();
        pq.pop();
        currentDistance = current.getDistance();

        if (shortestDist.find(current.getTarget()) == shortestDist.end()) {
            shortestDist[current.getTarget()] = currentDistance;
        } else if (currentDistance < shortestDist[current.getTarget()]) {
            shortestDist[current.getTarget()] = currentDistance; // Update new shortest distance to destination
        }

        for (auto dist : temp[current.getTarget()]) {
            Distance newDist(dist.getTarget(), dist.getDistance() + currentDistance);
            pq.push(newDist);
        }

        temp.erase(current.getTarget());
    }

    return shortestDist;
}


	private:
	map<string, set<Distance>> routeMap; 
	string inputFile;
	string startCity;
};

	
int main() {
	// test your methods here
	Routes route("map.txt");
	route.populateFiles();
	map<string, int> shortest = route.findShortestKnownDistance();
	for(auto& s : shortest) {
		cout<<s.first<<" : "<<s.second<<endl;
	}
	return 0;
}

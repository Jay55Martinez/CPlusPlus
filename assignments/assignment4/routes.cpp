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
    Distance(string city, int dist) {
        target = city;
        distance = dist;
    }

    string getTarget() {
        return target;
    }

    int getDistance() {
        return distance;
    }

    int compare(Distance other) {
        return distance- other.distance;
    }

    bool operator<(const Distance& other) const {
        return distance>other.distance;
    }

private:
    string target;
    int distance;
};

struct compare { // function object
    bool operator()(Distance& first, Distance& second) {
        return first.getDistance() > second.getDistance();
    }
};

class Routes {
public:
    Routes(string fileName) {
        inputFile = fileName;
    }

	// populates the route map
    void populateFiles() {
		// read map.txt to populate routeMap
        ifstream map_file(inputFile);
        if(!map_file.is_open()) {
            throw invalid_argument("File does not exist");
        } else {
            string route_info;
            while(getline(map_file, route_info)) {
                string from, to;
                int dist;
                size_t start = 0;
                size_t end = route_info.find(" ");

                if(end != string::npos) {
                    from = route_info.substr(start, end - start);
                    start = end + 1;
                    end = route_info.find(" ", start);
                    if(end != string::npos) {
                        to = route_info.substr(start, end - start);
                        start = end + 1;
                        dist = stoi(route_info.substr(start));

                        Distance new_dist(to, dist);

                        if(route_map.find(from) == route_map.end()) {
                            set<Distance> set_dist{ new_dist };
                            route_map[from] = set_dist;
                        } else {
                            route_map[from].insert(new_dist);
                        }

                        // Add reverse connection as well
                        Distance reverse_dist(from, dist);
                        if(route_map.find(to) == route_map.end()) {
                            set<Distance> set_reverse_dist{ reverse_dist };
                            route_map[to] = set_reverse_dist;
                        } else {
                            route_map[to].insert(reverse_dist);
                        }
                    }
                }
            }
            map_file.close();
        }
    }

	// returns the shortest route from the start point 
    map<string, int> findShortestKnownDistance() {
		// declare variables
        map<string, set<Distance>> temp = route_map;
        map<string, int> shortest_dist;
        string starting_point = temp.begin()->first;
        int current_dist = 0;
        priority_queue<Distance, vector<Distance>, compare> pq; // smallest distance comes first
        shortest_dist[starting_point] = current_dist;

		// add to the queue
        for(const auto& dist : temp[starting_point]) {
            pq.push(dist);
        }

		// start loop till queue is empty
        while(!pq.empty()) {
            Distance current = pq.top();
            pq.pop();
            current_dist = current.getDistance();

			// if it is not in the map add it 
            if(shortest_dist.find(current.getTarget()) == shortest_dist.end()) {
                shortest_dist[current.getTarget()] = current_dist;
				// add all other connected nodes
                for(auto dist : temp[current.getTarget()]) {
                    Distance new_dist(dist.getTarget(), dist.getDistance() + current_dist);
                    pq.push(new_dist);
                }
			// check if the current version is smaller than the one stored in the map
            } else if(current_dist<shortest_dist[current.getTarget()]) {
                shortest_dist[current.getTarget()] = current_dist;
            }
        }
        return shortest_dist;
    }

private:
    map<string, set<Distance>> route_map;
    string inputFile;
};

int main() {
    Routes route("map.txt");
    route.populateFiles();
    map<string, int> shortest = route.findShortestKnownDistance();
    for(auto& s : shortest) {
        cout<<s.first<<": "<<s.second<<endl;
    }
    return 0;
}

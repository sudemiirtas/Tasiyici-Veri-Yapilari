#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <vector>

class GPS {
public:
    double latitude;
    double longitude;
    std::string location_name;
};
 
std::chrono::high_resolution_clock::time_point start;

void start_timer() {
    // chrono kutuphanesi kullanarak zaman olcumunu icin saatin baslatilmasini gerceklestirir
    start = std::chrono::high_resolution_clock::now();
}
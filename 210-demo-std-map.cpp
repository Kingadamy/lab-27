#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails; // change this to tuple

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Joey"] = {7, "Orangutan", "YOLO!"};
    villagerDetails["Snookie"] = {4, "Shark", "I'm not dangerous at all!"};
    villagerDetails.insert({"Abdu", {9, "Camel", "I'm parched!"}});

    // access the map using a range-based for loop
    cout << "Villager friendship level and details (range-based for loop):" << endl;
    for (auto pair : villagerDetails) {

        // we can use std::get to access tuple elements
        cout << pair.first << " ["; 
        cout << get<0>(pair.second) << ", ";  // will print friendship level
        cout << get<2>(pair.second) << ", "; // print species
        cout << get<3>(pair.second) << ", " << endl; // print catchprase
    
    }
    
    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerDetails.begin(); 
                                               it != villagerDetails.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerDetails.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerDetails.find(searchKey);
    if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}

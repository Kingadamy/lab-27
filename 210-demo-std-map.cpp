#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

// create helper function to make it easier for me and can call whenever i need
void printVillagers(const map<string, tuple<int, string, string>>& villagerMap) {
    cout << "\nVillager details:" << endl;
    for (auto pair : villagerMap) {
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", ";  // friendship
        cout << get<1>(pair.second) << ", "; // species
        cout << get<2>(pair.second) << "]" << endl; // catchphrase
    }
}

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails; // change this to tuple

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Joey"] = {7, "Orangutan", "YOLO!"};
    villagerDetails["Snookie"] = {4, "Shark", "I'm not dangerous at all!"};
    villagerDetails.insert({"Abdu", {9, "Camel", "I'm parched!"}});

    int choice = 0;
    string name;

    // I can use a switch statment for the menu and to run the functions
    do{
        //print menu:
        cout << "\nMenu:\n"
             << "1. Increase Friendship\n"
             << "2. Decrease Friendship\n"
             << "3. Search for Villager\n"
             << "4. Exit\n"
             << "Enter choice: ";

        // 2. Get user choice
        cin >> choice;

        switch (choice) {
            case 1: { // increase friendship
                cout << "Enter villager name: ";
                cin >> name;
                auto it = villagerDetails.find(name);

                if (it != villagerDetails.end()) {
                    get<0>(it->second)++;
                    cout << name << "'s friendship increased!" << endl;
                } else {
                    cout << name << " not found." << endl;
                }
                
                printVillagers(villagerDetails);
                break;

            }

           case 2: { // Decrease Friendship
                cout << "Enter villager name: ";
                cin >> name;
                auto it = villagerDetails.find(name);

                if (it != villagerDetails.end()) {
                    if (get<0>(it->second) > 0) {
                        get<0>(it->second)--; 
                        cout << name << "'s friendship decreased!" << endl;
                    } else {
                        cout << name << "'s friendship is already 0!" << endl;
                    }
                } else {
                    cout << name << " not found." << endl;
                }
                
                printVillagers(villagerDetails);
                break;
            }
            case 3: { // Search for Villager
                cout << "Enter villager name to search for: ";
                cin >> name;
                auto it = villagerDetails.find(name);

        }
    }


    // access the map using a range-based for loop
    cout << "Villager friendship level and details (range-based for loop):" << endl;
    for (auto pair : villagerDetails) {

        // we can use std::get to access tuple elements
        cout << pair.first << " ["; 
        cout << get<0>(pair.second) << ", ";  // will print friendship level
        cout << get<1>(pair.second) << ", "; // print species
        cout << get<2>(pair.second) << "] " << endl; // print catchprase
    
    }

    // access the map using iterators
    cout << "\nVillagers details (iterators):" << endl;
    // update this to tuple
    for (map<string, tuple<int, string, string>>::iterator it = villagerDetails.begin(); 
        it != villagerDetails.end(); ++it) {

            // use std::get to access the elements 
            cout << it->first << " ["; // Print name
            cout << get<0>(it->second) << ", "; // Print friendship
            cout << get<1>(it->second) << ", "; // Print species
            cout << get<2>(it->second) << "]" << endl; // Print catchphrase
    }

        
     // delete an element
    villagerDetails.erase("Snookie");

    // search for an element using .find() to avoid errors
    string searchKey = "Joey";
    auto it = villagerDetails.find(searchKey);

    
    if (it != villagerDetails.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s details: ";

        // Use std::get to print instead of loop
        cout << "[" 
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    } else {
        cout << endl << searchKey << " not found." << endl;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    // create the menu to run programs



    return 0;
}

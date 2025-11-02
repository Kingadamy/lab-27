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
             << "1. Add Villager\n"         
             << "2. Delete Villager\n"      
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit\n"              
             << "Enter choice: ";

        // 2. Get user choice
        cin >> choice;

        // clear the enter key 
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1: { // add villager
                int friendship;
                string species, catchphrase;

                cout << "Villager name: ";
                getline(cin, name); // Use getline for names with spaces

                cout << "Friendship level: ";
                cin >> friendship;

                cin.ignore(1000, '\n'); 

                cout << "Species: ";
                getline(cin, species);

                cout << "Catchphrase: ";
                getline(cin, catchphrase);

                // Add the new data to the map
                villagerDetails[name] = {friendship, species, catchphrase};
                
                cout << name << " added." << endl;
                printVillagers(villagerDetails);
                break;
            }   
                // // increase friendship
                // cout << "Enter villager name: ";
                // getline(cin, name);
                // auto it = villagerDetails.find(name);

                // if (it != villagerDetails.end()) {
                //     get<0>(it->second)++;
                //     cout << name << "'s friendship increased!" << endl;
                // } else {
                //     cout << name << " not found." << endl;
                // }
                
                // printVillagers(villagerDetails);
                // break;

           case 2: { // Delete villager now

            cout << "Enter villager name to delete: ";
                getline(cin, name); 

                if (villagerDetails.erase(name) > 0) {
                    // .erase() returns 1 if it found and deleted the item
                    cout << name << " was deleted." << endl;
                } else {
                    cout << "Sorry, " << name << " not found." << endl;
                }
                
                printVillagers(villagerDetails);
                break;
            }



                // cout << "Enter villager name: ";
                // getline(cin, name);
                // auto it = villagerDetails.find(name);

                // if (it != villagerDetails.end()) {
                //     if (get<0>(it->second) > 0) {
                //         get<0>(it->second)--; 
                //         cout << name << "'s friendship decreased!" << endl;
                //     } else {
                //         cout << name << "'s friendship is already 0!" << endl;
                //     }
                // } else {
                //     cout << name << " not found." << endl;
                // }
                
                // printVillagers(villagerDetails);
                // break;
            
            case 3: { // Search for Villager
                cout << "Enter villager name to search for: ";
                 getline(cin, name);
                auto it = villagerDetails.find(name);

                if (it != villagerDetails.end()) {
                    cout << "Found " << name << "'s details: ";
                    cout << "[" << get<0>(it->second) << ", "
                         << get<1>(it->second) << ", "
                         << get<2>(it->second) << "]" << endl;
                } else {
                    cout << name << " not found." << endl;
                }
                
                printVillagers(villagerDetails);
                break;
            }
            case 4: { // Exit
                cout << "Goodbye!" << endl;
                break;
            }
            default: { 
                cout << "Invalid choice. Please enter a number 1-4." << endl;
                break;
            }

        }
    }
    
    while (choice != 4);
    
    return 0;
}

//milestone 3
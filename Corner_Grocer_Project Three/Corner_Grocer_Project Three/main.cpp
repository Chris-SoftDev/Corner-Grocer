#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency; // Map to store item frequency

public:
    // Function to read data from file and populate itemFrequency map
    void readDataFromFile() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");
        string itemName;

        while (inputFile >> itemName) {
            // Increment the frequency of the item or initialize it to 1 if not found
            itemFrequency[itemName]++;
        }

        inputFile.close();
    }

    // Function to display menu
    void displayMenu() {
        cout << "\nWelcome to Corner Grocer's Item Listing\n";
        cout << "========================================================\n";
        cout << "Menu:\n";
        cout << "1. Find frequency of a specific item\n";
        cout << "2. Display frequency of all items\n";
        cout << "3. Display histogram of item frequencies\n";
        cout << "4. Exit\n";
        cout << "========================================================\n\n";
    }

    // Function to find frequency of a specific item
    void findFrequency() {
        string searchItem;

        clearScreen();
        cout << "Enter the item you want to search for: ";
        cin >> searchItem;

        if (itemFrequency.find(searchItem) != itemFrequency.end()) {
            cout << "\nFrequency of " << searchItem << ": " << itemFrequency[searchItem] << "\n";
        }
        else {
            cout << "Item not found\n";
        }
    }

    // Function to display frequency of all items
    void displayAllItemsFrequency() {
        clearScreen();
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " " << entry.second << "\n";
        }
    }

    // Function to display histogram of item frequencies
    void displayHistogram() {
        clearScreen();
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " " << string(entry.second, '*') << "\n";
        }
    }

    // Function to save data to frequency.dat file
    void saveDataToFile() {
        ofstream outputFile("frequency.dat");

        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " " << entry.second << "\n";
        }

        outputFile.close();
    }

    void clearScreen() {
        system("cls"); // Use "cls" for Windows, "clear" for Unix-like systems
    };
};

int main() {
    ItemTracker itemTracker;
    itemTracker.readDataFromFile(); // Read data from file
    itemTracker.saveDataToFile(); // Save data to frequency.dat file

    int choice;

    do {
        itemTracker.displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            itemTracker.findFrequency();
            break;
        case 2:
            itemTracker.displayAllItemsFrequency();
            break;
        case 3:
            itemTracker.displayHistogram();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

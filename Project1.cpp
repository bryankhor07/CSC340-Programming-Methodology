#include<iostream>
using namespace std;

void printOptions();
void storeNewLocation(int*, int*, int*, int, int);
void showStoredLocations(int*, int*, int*);
void removeLocation(int*, int*, int*, int);

int main()
{
    const int length = 10;
    int x_Coordinate[length]; // X coordinate
    int y_Coordinate[length]; // Y coordinate
    int numOfLocations = 0;   // Keeps track on the number of locations stored
    int option = 0;           // Store user input

    // This while loop controls the entire program
    // It first prints out the menu options
    // Then, I used if-else statements for each option
    // Option 1 stores the user's coordinates
    // Option 2 removes the selected coordinates
    // Option 3 displays the coordinates
    // Option 4 exits the program
    while (true)
    {
        printOptions();
        cin >> option;
        int x = 0;
        int y = 0;
        if (option == 1) {
            cout << "\nEnter X coordinate: ";
            cin >> x;
            cout << "\nEnter Y coordinate: ";
            cin >> y;
            if (numOfLocations == 10) {
                cout << "You can only store 10 coordinates." << endl;
                continue;
            }
            storeNewLocation(x_Coordinate, y_Coordinate, &numOfLocations, x, y);
        }
        else if (option == 2) {
            if (numOfLocations == 0) {
                cout << "\nThere are no locations stored.\n";
                continue;
            }
            int remove = 0;
            cout << "\nThe following locations are stored: " << endl;
            showStoredLocations(x_Coordinate, y_Coordinate, &numOfLocations);
            cout << "\nWhich location do you want to remove?" << endl;
            cin >> remove;
            removeLocation(x_Coordinate, y_Coordinate, &numOfLocations, remove);
        }
        else if (option == 3) {
            cout << "\nThe following locations are stored: " << endl;
            showStoredLocations(x_Coordinate, y_Coordinate, &numOfLocations);
        }
        else {
            break;
        }
    }
    return 0;
}

// Print the menu options 
void printOptions()
{
    cout << "\nChoose an option:" << endl;
    cout << "1) Store a new location" << endl;
    cout << "2) Remove a location" << endl;
    cout << "3) Show stored locations" << endl;
    cout << "4) Exit" << endl << endl;
}

// Store a new location 
void storeNewLocation(int* x_Coordinate, int* y_coordinate, int* numOfLocations, int x, int y)
{
    x_Coordinate[*numOfLocations] = x;
    y_coordinate[*numOfLocations] = y;
    (*numOfLocations)++;
    cout << "\nLocation " << x << ", " << y << " has been stored" << endl;
}

// Display stored locations
void showStoredLocations(int* x_Coordinate, int* y_Coordinate, int* numOfLocations)
{
    for (int i = 0; i < *numOfLocations; i++) {
        cout << i + 1 << ": " << x_Coordinate[i] << ", " << y_Coordinate[i] << endl;
    }
}

// Remove a specific location chosen by the user
void removeLocation(int* x_Coordinate, int* y_Coordinate, int* numOfLocations, int remove)
{
    cout << "\nLocation " << x_Coordinate[remove - 1] << ", " << y_Coordinate[remove - 1] << " has been removed from memory" << endl;
    for (int i = remove - 1; i < *numOfLocations; i++) {
        x_Coordinate[i] = x_Coordinate[i + 1];
        y_Coordinate[i] = y_Coordinate[i + 1];
    }
    (*numOfLocations)--;
}
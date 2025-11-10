#include <iostream>
#include <string>
#include <algorithm>
#include <limits> 

using namespace std;

// --- Function Declarations ---
void starting_room();
void west_corridor();
void ending_win();
void ending_game_over();

// --- Utility Function to Normalize Input (to lowercase) ---
string normalize_input(string input) {
    // Convert the entire string to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

// -------------------------------------------------------------
// Function 1: The Starting Room
// -------------------------------------------------------------
void starting_room() {
    string choice;
    bool validInput = false;
    
    // Clear any potential leftover bad input from the buffer (good practice)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n----------------------------------------\n";
    cout << "You wake up in a small, damp stone chamber. The only light comes from a narrow crack in the ceiling.\n";
    cout << "In front of you, there is a heavy wooden door to the WEST and a small CHEST to the EAST.\n";
    cout << "----------------------------------------\n";

    // Loop until the user provides valid input that moves the story forward
    while (!validInput) {
        cout << "What do you choose to do? (EXAMINE CHEST / GO WEST)\n";
        cout << "> ";
        
        if (!getline(cin, choice)) {
            cout << "An input error occurred. Exiting game.\n";
            return; 
        }

        choice = normalize_input(choice);

        if (choice == "examine chest" || choice == "chest") {
            cout << "\nYou walk up to the chest. It's made of dark, old wood and has a simple padlock.\n";
            cout << "You manage to pry the lid open with your fingers. Inside, you find a small, gleaming GOLD COIN.\n";
            
            // The chest is examined. Now, the player must choose to go WEST.
            cout << "There is nothing more to do here. You turn towards the door in the west.\n";
            validInput = true; 
            west_corridor(); // Move to the next function/location

        } else if (choice == "go west" || choice == "west") {
            validInput = true; 
            west_corridor(); // Move to the next function/location
            
        } else {
            // Input was invalid – the loop runs again (no recursion!)
            cout << "\n❌ Command not understood. Try simpler commands (e.g., WEST or CHEST).\n";
        }
    }
}

// -------------------------------------------------------------
// Function 2: The West Corridor
// -------------------------------------------------------------
void west_corridor() {
    string choice;
    bool validInput = false;

    cout << "\n----------------------------------------\n";
    cout << "You open the heavy door and step out into a dark corridor.\n";
    cout << "You hear a faint, scraping sound further away.\n";
    cout << "The corridor continues NORTH. The door you came from is to the SOUTH.\n";
    cout << "----------------------------------------\n";

    while (!validInput) {
        cout << "What do you choose to do? (GO NORTH / GO SOUTH / INVESTIGATE SCRAPING)\n";
        cout << "> ";
        
        if (!getline(cin, choice)) { return; }

        choice = normalize_input(choice);

        if (choice == "go north" || choice == "north") {
            validInput = true;
            ending_win(); 
        } else if (choice == "go south" || choice == "south") {
            validInput = true;
            starting_room(); // Go back to the starting room
        } else if (choice == "investigate scraping" || choice == "scraping") {
            validInput = true;
            ending_game_over(); // A bad choice!
        } else {
            cout << "\n❌ Unclear command. Choose a direction or investigate the sound.\n";
        }
    }
}

// -------------------------------------------------------------
// Function 3: Ending (Win)
// -------------------------------------------------------------
void ending_win() {
    cout << "\n****************************************\n";
    cout << "  You see sunlight! You have found your way out!\n";
    cout << "  CONGRATULATIONS! The adventure is over.\n";
    cout << "****************************************\n";
}

// -------------------------------------------------------------
// Function 4: Ending (Game Over)
// -------------------------------------------------------------
void ending_game_over() {
    cout << "\n--- GAME OVER ---\n";
    cout << "As you walk toward the scraping sound, you fall right into a deep, hidden chasm!\n";
    cout << "Your adventure ends here.\n";
}

// -------------------------------------------------------------
// Main Function (Starts the game)
// -------------------------------------------------------------
int main() {
    cout << "--- WELCOME TO CHOOSE YOUR ADVENTURE ---\n";
    starting_room(); // Begin the game
    
    // Wait for the user before closing the program
    cout << "\nPress ENTER to exit the program...";
    cin.get();
    
    return 0;
}
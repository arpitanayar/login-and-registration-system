#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if a username already exists
bool userExists(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username)
            return true;
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;
    cout << "Register\nEnter username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    cout << "Login\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool success = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }

    if (success)
        cout << "Login successful! Welcome, " << username << ".\n";
    else
        cout << "Error: Invalid username or password.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}


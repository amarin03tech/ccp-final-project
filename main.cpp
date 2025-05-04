#include "final-project.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int choice;
    string password;
    const string filename = "passwords.txt";

    do {
        cout << "Passsword Generator Menu"<<endl;
        cout << "1 .Generate defailt password" << endl;
        cout << "2. Generate custom-length password" << endl;
        cout << "3. View saved passwords" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: (1-4): " << endl;
        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                password = generatePassword();
                cout << "Generated password: " << password << endl;
                savePassword(password, filename);
                break;
            case 2: {
                int lenght;
                cout << "Enter desired password lenght (8-20): ";
                cin >> lenght;
                while (cin.fail() || lenght < 8 || lenght > 20) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid lenght. Enter between 8 and 20: ";
                    cin >> lenght;
                }
                password = generatePassword(lenght);
                cout << "Generated password: " << password << "\n";
                savePassword(password, filename);
                break;
            }
            case 3:
                loadPasswords(filename);
                break;
            case 4:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
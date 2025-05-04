#include "final-project.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

char getCharType(int type) {
    switch (type) {
        case 1: return 'A' + rand() % 26;
        case 2: return 'a' + rand() % 26;
        case 3: return '0' + rand() % 10;
        case 4: {
            string symbols = "!@#$%^&*";
            return symbols[rand() % symbols.length()];
        }
        default: return '*';
    }
}

string generatePassword() {
    return generatePassword(12);
}

string generatePassword(int lenght) {
    string password = "";
    for (int i = 0; i < lenght; ++i) {
        int type = rand() % 4 + 1;
        password += getCharType(type);
    }
    return password;
}

void savePassword(const string& password, const string& filename) {
    ofstream out(filename, ios::app);
    if (out) {
        out << password << "\n";
        cout << "Password saved to file.\n";
    } else {
        cerr << "Error saving password.\n";
    }
    out.close();
}

void loadPassword(const string& filename) {
    ifstream in(filename);
    string line;
    if (!in) {
        cerr << "File not found.\n";
        return;
    }
    cout << "Saved passwords:\n";
    while (getline(in, line)) {
        cout << line << "\n";
    }
    in.close();
}
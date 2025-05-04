#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
using namespace std;

string generatePassword();
string generatePassword(int lenght);
char hetCharType(int type);
void savePassword(const string& password, const string& filename);
void loadPasswords(const string& filename);

#endif
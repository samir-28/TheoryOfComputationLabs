#include <iostream>
#include <string>

using namespace std; // Use the standard namespace

void displayPrefixes(const string& str) {
    cout << "Prefixes of the string \"" << str << "\":";
    for (size_t i = 0; i <= str.length(); ++i) {
        cout << str.substr(0, i) << endl; // Display prefix
    }
}

void displaySuffixes(const string& str) {
    cout <<"\nSuffixes of the string \"" << str << "\":\n";
    for (size_t i = 0; i < str.length(); ++i) {
        cout << str.substr(i) << endl; // Display suffix
    }
}

int main() {
    string input;
 
    cout << "Enter a string: ";
    getline(cin, input); // Read the input string

    displayPrefixes(input); // Call function to display prefixes
    displaySuffixes(input); // Call function to display suffixes

    return 0;
}

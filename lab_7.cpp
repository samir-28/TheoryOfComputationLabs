#include <iostream>
#include <cctype> // For isalpha, isalnum
#include <string>

using namespace std;

bool isValidIdentifier(const string& input) {
    // Check if the input is empty
    if (input.empty()) return false;

    // DFA starts in the initial state (state 0)
    int state = 0;

    for (size_t i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (state == 0) {
            // First character must be a letter or underscore
            if (isalpha(ch) || ch == '_') {
                state = 1; // Move to state 1
            } else {
                return false; // Invalid start character
            }
        } else if (state == 1) {
            // Subsequent characters can be alphanumeric or underscore
            if (isalnum(ch) || ch == '_') {
                state = 1; // Stay in state 1
            } else {
                return false; // Invalid character in identifier
            }
        }
    }

    // If we finish in state 1, it's a valid identifier
    return (state == 1);
}

int main() {
    string input;
    cout << "Enter a string to check if it's a valid C identifier: ";
    cin >> input;

    if (isValidIdentifier(input)) {
        cout << "The string is a valid C identifier.\n";
    } else {
        cout << "The string is not a valid C identifier.\n";
    }

    return 0;
}
 
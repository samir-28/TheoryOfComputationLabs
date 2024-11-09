#include <iostream>
#include <string>

using namespace std;

bool isAcceptedByDFA(const string& input) {
    int state = 0; // Start at initial state 0

    for (char ch : input) {
        if (ch == 'a') {
            // Transition for 'a'
            if (state == 0) {
                state = 0; // Stay in state 0 if already in state 0
            } else if (state == 1) {
                state = 0; // Move to state 0 if in state 1
            }
        } else if (ch == 'b') {
            // Transition for 'b'
            if (state == 0) {
                state = 1; // Move to state 1 if in state 0
            } else if (state == 1) {
                state = 1; // Stay in state 1 if already in state 1
            }
        } else {
            // Invalid character
            cout << "Invalid input. Only 'a' and 'b' are allowed.\n";
            return false;
        }
    }

    // Check if we ended in the accepting state (state 1)
    return state == 1;
}

int main() {
    string input;
    cout << "Enter a string over the alphabet {a, b}: ";
    cin >> input;

    if (isAcceptedByDFA(input)) {
        cout << "The string is accepted by the DFA (it ends with 'b').\n";
    } else {
        cout << "The string is not accepted by the DFA (it does not end with 'b').\n";
    }

    return 0;
}
 
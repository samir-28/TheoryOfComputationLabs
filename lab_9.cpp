#include <iostream>
#include <string>

using namespace std;

class NFA {
public:
    // Function to check if the input string is accepted by the NFA
    bool isAccepted(const string& input) {
        int state = 0; // Start at state 0

        for (char ch : input) {
            switch (state) {
                case 0: // Initial state
                    if (ch == 'a') {
                        state = 1; // Move to state 1 on 'a'
                    }
                    // No transition for 'b', stay in state 0
                    break;

                case 1: // State after reading 'a'
                    if (ch == 'b') {
                        state = 2; // Move to state 2 on 'b'
                    } else {
                        state = 1; // Stay in state 1 on 'a'
                    }
                    break;

                case 2: // State after reading 'ab'
                    if (ch == 'a') {
                        state = 3; // Move to accepting state 3 on 'a'
                    } else {
                        state = 0; // If not 'a', go back to state 0
                    }
                    break;

                case 3: // Accepting state (after reading 'aba')
                    // Stay in accepting state, as we've already seen 'aba'
                    break;
            }
        }

        // Accept the string if it ends in the accepting state (state 3)
        return state == 3;
    }
};

int main() {
    NFA nfa;
    string input;

    cout << "Enter a string containing characters {a, b}: ";
    cin >> input;

    // Validate input
    for (char ch : input) {
        if (ch != 'a' && ch != 'b') {
            cerr << "Invalid character in input. Only 'a' and 'b' are allowed." << endl;
            return 1;
        }
    }

    // Check if the string is accepted by the NFA
    if (nfa.isAccepted(input)) {
        cout << "The string is accepted by the NFA." << endl;
    } else {
        cout << "The string is not accepted by the NFA." << endl;
    }

    return 0;
}

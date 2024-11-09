#include <iostream>
#include <stack>
#include <string>

using namespace std;

class PDA {
public:
    // Function to process input and determine acceptance
    bool processInput(const string& input) {
        stack<char> s;  // Stack to keep track of 'a's

        // Process each character in the input string
        for (char symbol : input) {
            if (symbol == 'a') {
                s.push('A');  // Push 'A' for each 'a' encountered
            } else if (symbol == 'b') {
                if (!s.empty()) {
                    s.pop();  // Pop 'A' for each 'b'
                } else {
                    return false;  // More 'b's than 'a's
                }
            } else {
                return false;  // Invalid symbol
            }
        }

        // Accept if the stack is empty at the end of input
        return s.empty();
    }
};

int main() {
    PDA pda;  // Create an instance of the PDA
    string input;

    cout << "Enter a string consisting of 'a's followed by 'b's: ";
    cin >> input;

    if (pda.processInput(input)) {
        cout << "Accepted: The string has equal number of 'a's followed by 'b's." << endl;
    } else {
        cout << "Rejected: The string does not have equal number of 'a's followed by 'b's." << endl;
    }

    return 0;
}

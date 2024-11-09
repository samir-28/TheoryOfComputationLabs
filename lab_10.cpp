#include <iostream>
#include <stack>
#include <string>

using namespace std;

class PDA {
public:
    bool processInput(const string& input) {
        stack<char> s;  // Stack to keep track of 'a's

        for (char symbol : input) {
            if (symbol == 'a') {
                s.push('A');  // Push 'A' for each 'a'
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

        // Check if stack is empty for acceptance
        return s.empty();
    }
};

int main() {
    PDA pda;
    string input;

    cout << "Enter a string consisting of 'a' and 'b': ";
    cin >> input;

    if (pda.processInput(input)) {
        cout << "Accepted: The number of 'a's and 'b's are equal." << endl;
    } else {
        cout << "Rejected: The number of 'a's and 'b's are not equal." << endl;
    }

    return 0;
}

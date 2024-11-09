#include <iostream>
#include <string>

using namespace std;

bool isAcceptedByDFA(const string& input) {
    int state = 0; // Start at the initial state

    for (char ch : input) {
        switch (state) {
            case 0:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 0;
                break;
            case 1:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 2;
                break;
            case 2:
                if (ch == 'a') state = 3;
                else if (ch == 'b') state = 0;
                break;
            case 3:
                // Remain in accepting state 3
                return true;
        }
    }

    // Check if we ended in the accepting state
    return (state == 3);
}

int main() {
    string input;
    cout << "Enter a string over the alphabet {a, b}: ";
    cin >> input;

    if (isAcceptedByDFA(input)) {
        cout << "The string is accepted by the DFA (it contains 'aba').\n";
    } else {
        cout << "The string is not accepted by the DFA (it does not contain 'aba').\n";
    }

    return 0;
}

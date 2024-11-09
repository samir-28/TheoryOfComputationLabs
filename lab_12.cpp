#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TuringMachine {
public:
    bool processInput(string &tape) {
        int head = 0;
        int length = tape.size();

        // Loop to simulate Turing Machine operation
        while (true) {
            // Move to the first unmarked 'a' and mark it as 'X'
            while (head < length && tape[head] != 'a') head++;
            if (head == length) break;  // No unmarked 'a' found, exit loop
            tape[head] = 'X';

            // Move to the first unmarked 'b' after this 'a' and mark it as 'Y'
            int tempHead = head + 1;
            while (tempHead < length && tape[tempHead] != 'b') tempHead++;
            if (tempHead == length) return false;  // No matching 'b' found, reject
            tape[tempHead] = 'Y';

            // Reset head to start position to search for the next 'a'
            head = 0;
        }

        // Check if any unmarked 'a' or 'b' remains, which would indicate unequal counts
        for (char c : tape) {
            if (c == 'a' || c == 'b') return false;  // Unmatched 'a' or 'b' found
        }

        return true;  // All 'a's matched with 'b's
    }
};

int main() {
    TuringMachine tm;
    string input;

    cout << "Enter a string consisting of 'a's followed by 'b's: ";
    cin >> input;

    if (tm.processInput(input)) {
        cout << "Accepted: The string has equal number of 'a's followed by 'b's." << endl;
    } else {
        cout << "Rejected: The string does not have equal number of 'a's followed by 'b's." << endl;
    }

    return 0;
}

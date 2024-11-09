#include <iostream>
#include <string>

using namespace std;

bool isAcceptedByNFA(const string& input) {
    int n = input.size();

    // Start in initial state and track last two characters
    if (n < 2) return false;  // If length is less than 2, it can't end with "ab"

    // Check if last two characters are "ab"
    return input[n - 2] == 'a' && input[n - 1] == 'b';
}

int main() {
    string input;
    cout << "Enter a string over the alphabet {a, b}: ";
    cin >> input;

    if (isAcceptedByNFA(input)) {
        cout << "The string is accepted by the NFA (it ends with 'ab').\n";
    } else {
        cout << "The string is not accepted by the NFA (it does not end with 'ab').\n";
    }

    return 0;
}

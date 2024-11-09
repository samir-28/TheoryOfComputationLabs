#include <iostream>
#include <string>

using namespace std;

void displayPrefix(const string& input, int trailingCount) {
    int prefixLength = input.length() - trailingCount;
    cout << "The prefix is: " << input.substr(0, prefixLength) << endl;
}

void displaySuffix(const string& input, int leadingCount) {
    cout << "The suffix is: " << input.substr(leadingCount) << endl;
}

int main() {
    string input;
    int trailingCount, leadingCount;
 
    cout << "Enter the string: ";
    getline(cin, input); // Safely read the entire line of input

    cout << "Enter the number of trailing symbols to be removed: ";
    cin >> trailingCount;

    if (trailingCount < input.length()) {
        displayPrefix(input, trailingCount);
    } else {
        cout << "Error: Trailing count exceeds the length of the string.\n";
    }

    cout << "Enter the number of leading symbols to be removed: ";
    cin >> leadingCount;

    if (leadingCount < input.length()) {
        displaySuffix(input, leadingCount);
    } else {
        cout << "Error: Leading count exceeds the length of the string.\n";
    }

    return 0;
}

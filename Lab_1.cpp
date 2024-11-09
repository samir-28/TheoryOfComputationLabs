#include <iostream>
#include <string>

using namespace std;

void substring1(const string& w, int start, int end) {
    cout << "The substring is: ";
    for (int i = start; i <= end; i++) {
        cout << w[i];
    }
    cout << endl;
}

int main() {
    string input;
    int start, end;

    // Input the string
    cout << "Enter the string: ";
    getline(cin, input);

    // Input start and end positions with validation
    while (true) {
        cout << "Enter the starting position of the substring: ";
        cin >> start;
        cout << "Enter the ending position of the substring: ";
        cin >> end;

        // Validate positions
        if (start >= 1 && end <= input.size() && start <= end) break;
        cout << "Invalid positions! Please enter values within range." << endl;
    }

    // Call the function to display the substring
    substring1(input, start - 1, end - 1);

    // Pause the program before exiting
    cout << "Press Enter to exit..." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
  
#include <iostream>
#include <string>

using namespace std;

string substring2(const string& w, int a, int b) {
    // Check if the starting position and number of symbols are valid
    if (a < 0 || a >= w.size() || b < 0) {
        return "Invalid positions or length!";
    }
    
    // Extract the substring from position `a` with `b` symbols
    return w.substr(a, b);
}

int main() {
    string w;
    int a, b;

    // Get input from the user
    cout << "Enter a string: ";
    getline(cin, w);
    cout << "Enter the starting position: ";
    cin >> a;
    cout << "Enter the number of symbols to extract: ";
    cin >> b;

    // Call substring2 function and display the result
    string result = substring2(w, a, b);
    cout << "Extracted substring: " << result << endl;

    return 0;
}

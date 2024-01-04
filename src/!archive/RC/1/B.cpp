#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    int shift = input.length() * input.length(); // Calculate the shift amount

    for (char &c : input) {
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26; // Perform the shifting operation
        }
    }

    cout << input << endl;
    return 0;
}
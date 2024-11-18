#include <iostream>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        string keyboard;
        string word;

        // Read the keyboard layout and the word to type
        cin >> keyboard;
        cin >> word;

        // Create a map of character positions
        unordered_map<char, int> position_map;
        for (int i = 0; i < 26; ++i) {
            position_map[keyboard[i]] = i;
        }

        // Initialize the total time to 0
        int total_time = 0;

        // Calculate the total time by iterating through the word
        for (int i = 1; i < word.size(); ++i) {
            total_time += abs(position_map[word[i]] - position_map[word[i - 1]]);
        }

        // Output the result for the current test case
        cout << total_time << endl;
    }

    return 0;
}

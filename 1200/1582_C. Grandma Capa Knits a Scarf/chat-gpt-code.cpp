#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Function to check if a string is a palindrome
bool is_palindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Main function to process each test case
int main() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        int n;
        string s;
        cin >> n >> s;  // Read the length and the string

        // If the string is already a palindrome, no need to delete anything
        if (is_palindrome(s)) {
            cout << 0 << endl;
            continue;
        }

        // Set to store the unique characters in the string
        unordered_set<char> unique_chars(s.begin(), s.end());
        int min_deletions = n;  // Start with the worst case (delete all characters)

        // Try removing each character and check if the result is a palindrome
        for (char c : unique_chars) {
            // Create a new string by removing all occurrences of character c
            string modified_string = "";
            for (char ch : s) {
                if (ch != c) {
                    modified_string += ch;
                }
            }

            // If the modified string is a palindrome, calculate the number of deletions
            if (is_palindrome(modified_string)) {
                int deletions = count(s.begin(), s.end(), c);
                min_deletions = min(min_deletions, deletions);
            }
        }

        // If we couldn't find any valid palindrome, output -1
        if (min_deletions == n) {
            cout << -1 << endl;
        } else {
            cout << min_deletions << endl;
        }
    }

    return 0;
}

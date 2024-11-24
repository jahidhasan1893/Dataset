#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        string s;
        cin >> s;  // The input string
        
        // Count occurrences of 'A', 'B', and 'C'
        int a_count = 0, b_count = 0, c_count = 0;
        for (char ch : s) {
            if (ch == 'A') a_count++;
            else if (ch == 'B') b_count++;
            else if (ch == 'C') c_count++;
        }

        // Check the condition for erasing all characters
        if (a_count + c_count == b_count) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

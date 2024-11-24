#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        char c;
        string s;
        
        cin >> n >> c >> s;
        
        // If the string is already all `c`, we don't need any operations
        bool all_c = true;
        for (char ch : s) {
            if (ch != c) {
                all_c = false;
                break;
            }
        }
        
        if (all_c) {
            cout << "0\n";
            continue;
        }

        // List of x values that will be used to make all characters equal to `c`
        vector<int> result;
        
        // Start from the smallest x and try to cover all positions that aren't `c`
        for (int x = 2; x <= n; ++x) {
            bool operation_needed = false;
            for (int i = 1; i <= n; ++i) {
                if (i % x != 0 && s[i - 1] != c) {
                    operation_needed = true;
                    break;
                }
            }
            if (operation_needed) {
                result.push_back(x);
                // Perform the operation: replace all non-x-multiples with c
                for (int i = 1; i <= n; ++i) {
                    if (i % x != 0 && s[i - 1] != c) {
                        s[i - 1] = c;
                    }
                }
            }
        }
        
        // After performing all the operations, print the result
        cout << result.size() << endl;
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

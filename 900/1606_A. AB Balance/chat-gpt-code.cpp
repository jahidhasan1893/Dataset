#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    // Function to count the number of "ab" and "ba"
    auto count_ab_ba = [&]() {
        int ab_count = 0, ba_count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b') ab_count++;
            if (s[i] == 'b' && s[i + 1] == 'a') ba_count++;
        }
        return make_pair(ab_count, ba_count);
    };
    
    // Get the initial counts of AB(s) and BA(s)
    auto [ab_count, ba_count] = count_ab_ba();
    
    // If already balanced, no change is needed
    if (ab_count == ba_count) {
        cout << s << endl;
        return;
    }

    // Modify the string until AB(s) == BA(s)
    while (ab_count != ba_count) {
        // Try to balance by changing either "ab" to "bb" or "ba" to "aa"
        for (int i = 0; i < n - 1; ++i) {
            if (ab_count > ba_count && s[i] == 'a' && s[i + 1] == 'b') {
                // Change "ab" to "bb"
                s[i] = 'b';
                ab_count--;
                ba_count++;
                break;
            } 
            else if (ba_count > ab_count && s[i] == 'b' && s[i + 1] == 'a') {
                // Change "ba" to "aa"
                s[i + 1] = 'a';
                ba_count--;
                ab_count++;
                break;
            }
        }
    }
    
    // Output the modified string
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

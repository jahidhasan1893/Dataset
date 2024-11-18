#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MOD 1000000007

// Function to determine if it's possible to make all elements zero for a given k
vector<int> find_valid_k(int n, const vector<int>& a) {
    vector<int> valid_k;

    // Check if all elements are the same
    bool all_equal = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            all_equal = false;
            break;
        }
    }

    if (all_equal) {
        // If all elements are the same, then all k values are valid
        for (int k = 1; k <= n; ++k) {
            valid_k.push_back(k);
        }
        return valid_k;
    }

    // Otherwise, check for each k if it is possible to eliminate all elements
    for (int k = 1; k <= n; ++k) {
        // We need to check if there's a combination of k elements that can reduce all to zero
        set<int> and_results;
        
        // Try all possible k-sized combinations of elements
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) == k) {
                int and_val = a[0];
                bool valid = true;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        and_val &= a[i];
                    }
                }
                if (and_val != 0) {
                    valid_k.push_back(k);
                    break;
                }
            }
        }
    }

    return valid_k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> valid_k = find_valid_k(n, a);

        // Output the result for this test case
        for (int i = 0; i < valid_k.size(); ++i) {
            cout << valid_k[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

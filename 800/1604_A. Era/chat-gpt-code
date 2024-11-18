#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int operations = 0;

        // Count how many elements are greater than their index (1-based)
        for (int i = 0; i < n; ++i) {
            if (a[i] > i + 1) {
                // We need to insert elements to fix this position
                operations++;
            }
        }

        // Output the result for this test case
        cout << operations << endl;
    }

    return 0;
}

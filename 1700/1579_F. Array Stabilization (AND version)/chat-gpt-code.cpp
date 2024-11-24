#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_set<string> seen;
        int steps = 0;

        // Function to convert array to string for cycle detection
        auto array_to_string = [](const vector<int>& arr) {
            string s;
            for (int num : arr) {
                s += to_string(num) + ",";
            }
            return s;
        };

        // Main loop to simulate the transformation
        while (true) {
            // Check if all elements are zero
            bool all_zero = true;
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                cout << steps << endl;
                break;
            }

            // Convert current array to string to detect cycles
            string current_state = array_to_string(a);
            if (seen.count(current_state)) {
                cout << -1 << endl;
                break;
            }
            seen.insert(current_state);

            // Perform the transformation
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
                // a^{→ d}_i = a[(i + n - d) % n]
                b[i] = a[i] & a[(i + n - d) % n];
            }

            a = b;
            steps++;
        }
    }
}

int main() {
    solve();
    return 0;
}

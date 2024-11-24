#include <iostream>
using namespace std;

void solve() {
    long long x_0, n;
    cin >> x_0 >> n;
    
    long long position = x_0;
    
    // Simulate the jumps
    for (long long i = 1; i <= n; ++i) {
        if (position % 2 == 0) {
            // Even position, jump to the left
            position -= i;
        } else {
            // Odd position, jump to the right
            position += i;
        }
    }
    
    // Output the final position
    cout << position << endl;
}

int main() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        solve();  // Process each test case
    }
    return 0;
}

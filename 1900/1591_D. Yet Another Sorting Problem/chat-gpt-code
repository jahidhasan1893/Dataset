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
        
        // To track if an element has been visited in its cycle
        vector<bool> visited(n, false);
        int cycle_count = 0;
        
        // Process each element to find cycles
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Start a new cycle from element i
                cycle_count++;
                int current = i;
                while (!visited[current]) {
                    visited[current] = true;
                    current = a[current] - 1; // move to the index a[current] (adjusted to 0-based index)
                }
            }
        }
        
        // If the number of cycles is odd, we can sort the array
        if (cycle_count % 2 == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

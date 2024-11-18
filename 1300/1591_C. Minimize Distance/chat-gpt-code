#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> depots(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> depots[i];
        }
        
        // Sort depots by absolute distance
        sort(depots.begin(), depots.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        
        long long total_distance = 0;
        
        // Process in batches of size k
        for (int i = 0; i < n; i += k) {
            int farthest_depot = depots[i];  // The farthest depot in this batch
            total_distance += 2 * abs(farthest_depot);  // Round trip for this batch
            
            // If this is the last trip (i.e., the last batch), don't count the return trip
            if (i + k >= n) {
                total_distance -= abs(farthest_depot);  // No return trip for the last batch
            }
        }
        
        cout << total_distance << endl;
    }
    
    return 0;
}

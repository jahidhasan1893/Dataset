#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Compute prefix sums to calculate sums of subarrays efficiently
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        
        int max_k = 0;
        
        // Try different values of k starting from the largest possible k
        for (int k = 1; k <= n; k++) {
            long long last_sum = -LLONG_MAX;
            int last_end = -1;
            bool valid = true;
            
            for (int start = 0; start + k <= n; start++) {
                int end = start + k - 1;
                long long current_sum = prefix[end + 1] - prefix[start];
                
                if (current_sum <= last_sum) {
                    continue;  // The sum is not strictly greater, skip this segment
                }
                
                last_sum = current_sum;
                last_end = end;
                
                if (last_end + 1 >= n) {
                    break;  // We have exhausted the array without finding a valid solution
                }
            }
            
            if (last_end + 1 <= n) {
                max_k = k;  // We found a valid k, so update the max_k
            }
        }
        
        cout << max_k << endl;
    }

    return 0;
}

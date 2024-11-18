#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        
        // Read the array and calculate the sum
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        
        // Calculate target value
        if (2 * sum % n != 0) {
            cout << 0 << endl;
            continue;
        }
        
        long long target = 2 * sum / n;
        
        // Count frequencies of elements
        unordered_map<int, int> freq;
        for (int num : a) {
            freq[num]++;
        }
        
        long long count_pairs = 0;
        
        // Now, count valid pairs (i < j) such that a[i] + a[j] = target
        for (auto& entry : freq) {
            int x = entry.first;
            int count_x = entry.second;
            
            // We want to find how many times target - x appears in the array
            int y = target - x;
            if (y < x) continue;  // Ensure we count each pair once (i < j)
            
            if (x == y) {
                // If x == y, we need to choose 2 items from the count of x
                count_pairs += (count_x * (count_x - 1)) / 2;
            } else if (freq.count(y)) {
                // If x != y, we multiply the counts of x and y
                count_pairs += count_x * freq[y];
            }
        }
        
        cout << count_pairs << endl;
    }
    
    return 0;
}

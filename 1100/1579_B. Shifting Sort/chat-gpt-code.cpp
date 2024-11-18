#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform the left cyclic shift on a segment [l, r] with offset d
void cyclicShift(vector<int>& arr, int l, int r, int d) {
    // Convert 1-based index to 0-based index for convenience
    --l; --r;
    
    // Perform the left shift by moving arr[l..r] with offset d
    vector<int> temp(arr.begin() + l, arr.begin() + r + 1);
    for (int i = 0; i < (r - l + 1); ++i) {
        arr[l + i] = temp[(i + d) % (r - l + 1)];
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // To store the actions performed
        vector<pair<int, int>> actions;

        // Try to sort using a selection sort-like approach
        for (int i = 0; i < n - 1; ++i) {
            // Find the minimum element in the unsorted part arr[i..n-1]
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            
            // If min_idx is not i, we perform a cyclic shift to place the minimum element in position i
            if (min_idx != i) {
                // Perform cyclic shift for the segment [i+1, min_idx+1] (1-based)
                cyclicShift(arr, i + 1, min_idx + 1, 1);
                actions.push_back({i + 1, min_idx + 1});
            }
        }

        // Output the results
        cout << actions.size() << "\n";
        for (auto& action : actions) {
            cout << action.first << " " << action.second << " 1\n"; // Always shift by 1
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int countEversions(vector<int>& a) {
    int n = a.size();
    int k = 0;
    
    // Function to check if the array is sorted
    auto is_sorted = [](const vector<int>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    };

    // If the array is already sorted, return 0
    if (is_sorted(a)) return 0;

    // Perform the eversion until the array is sorted
    while (true) {
        k++;
        int x = a[n - 1];  // The last element
        vector<int> left, right;

        // Partition the array into left and right parts
        for (int i = 0; i < n; ++i) {
            if (a[i] <= x) {
                left.push_back(a[i]);
            } else {
                right.push_back(a[i]);
            }
        }

        // Reconstruct the array: left part followed by right part
        vector<int> new_a = left;
        new_a.insert(new_a.end(), right.begin(), right.end());

        // If no change, break the loop
        if (new_a == a) {
            break;
        }

        // Otherwise, update the array
        a = new_a;
    }
    
    return k;
}

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

        // Output the number of eversions for the current test case
        cout << countEversions(a) << endl;
    }

    return 0;
}

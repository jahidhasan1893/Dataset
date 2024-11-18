#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is composite
bool isComposite(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        int totalSum = 0;
        
        // Read the array and calculate the total sum
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }
        
        // Try to find the largest subset with a composite sum
        if (isComposite(totalSum)) {
            // If the sum of the entire array is composite, output the whole array
            cout << n << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            // If the sum is not composite, remove one element and check
            bool found = false;
            for (int i = 0; i < n; i++) {
                int subsetSum = totalSum - arr[i];
                if (isComposite(subsetSum)) {
                    cout << n - 1 << endl;
                    for (int j = 1; j <= n; j++) {
                        if (j != i + 1) {
                            cout << j << " ";
                        }
                    }
                    cout << endl;
                    found = true;
                    break;
                }
            }
            
            // It is guaranteed that a solution always exists, so we don't need to remove more than one element
            if (!found) {
                // This block should never be reached in this problem because a solution is guaranteed
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

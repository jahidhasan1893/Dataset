#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // number of test cases

    while (t--) {
        long long n;
        cin >> n;  // the target sum for this test case
        
        // Trying with l = 0
        long long l = 0;
        long long r = 0;
        
        // Start from r = 1 and adjust to find a valid solution
        for (r = 1; r <= 2 * n; ++r) {
            long long sum = (r * (r + 1)) / 2;  // sum from 1 to r
            if (sum >= n) {
                long long diff = sum - n;
                if (diff <= r) {
                    cout << diff << " " << r << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

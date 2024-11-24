#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

// Function to compute the k-th special number modulo MOD
long long findSpecialNumber(int n, int k) {
    long long result = 0;
    long long powerOfN = 1;  // n^0 initially
    while (k > 0) {
        if (k & 1) {  // If the current bit of k is 1
            result = (result + powerOfN) % MOD;
        }
        powerOfN = (powerOfN * n) % MOD;  // Compute the next power of n
        k >>= 1;  // Right shift k to process the next bit
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << findSpecialNumber(n, k) << endl;
    }
    return 0;
}

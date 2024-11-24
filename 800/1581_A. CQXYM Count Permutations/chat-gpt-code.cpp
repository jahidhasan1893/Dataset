#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 100000;

// Precompute factorials and inverse factorials
vector<long long> fact(MAX_N * 2 + 1, 1), inv_fact(MAX_N * 2 + 1, 1);

// Function to compute x^y % MOD using binary exponentiation
long long mod_exp(long long x, long long y, int mod) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute() {
    for (int i = 2; i <= MAX_N * 2; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_N * 2] = mod_exp(fact[MAX_N * 2], MOD - 2, MOD);  // Fermat's Little Theorem
    for (int i = MAX_N * 2 - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// Function to compute Catalan number C_n modulo MOD
long long catalan(int n) {
    return fact[2 * n] * inv_fact[n + 1] % MOD * inv_fact[n] % MOD;
}

int main() {
    int t;
    cin >> t;
    
    // Precompute all factorials and inverse factorials
    precompute();
    
    // Process each test case
    while (t--) {
        int n;
        cin >> n;
        cout << catalan(n) << endl;
    }
    
    return 0;
}

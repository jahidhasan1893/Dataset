#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate combinations C(n, 3) = n * (n-1) * (n-2) / 6
long long comb3(long long n) {
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    int N;
    double P;
    cin >> N >> P;

    // If P is 0, Johnny does not need to study any maps
    if (P == 0) {
        cout << 0 << endl;
        return 0;
    }

    // If P is 1, Johnny needs to study all maps except 1
    if (P == 1.0) {
        cout << N - 1 << endl;
        return 0;
    }

    // Total number of ways to pick 3 maps from N
    long long totalCombinations = comb3(N);

    for (int k = 1; k <= N; ++k) {
        long long notStudiedCombinations = comb3(N - k);
        
        // Probability that none of the studied maps are selected
        double probabilityNoStudied = (double) notStudiedCombinations / totalCombinations;

        // Probability that at least one studied map is selected
        double probabilityAtLeastOneStudied = 1.0 - probabilityNoStudied;

        // Check if this probability is enough
        if (probabilityAtLeastOneStudied >= P) {
            cout << k << endl;
            return 0;
        }
    }

    return 0;
}

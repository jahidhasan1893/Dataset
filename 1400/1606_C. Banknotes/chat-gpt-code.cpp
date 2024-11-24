#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long find_min_burles(int n, long long k, const vector<int>& a) {
    // Start from the smallest number which is 1
    long long current_sum = 0;
    long long banknotes_used = 0;

    // We will iterate over the denominations in descending order
    for (int i = n - 1; i >= 0; --i) {
        long long denomination = 1LL << a[i];  // This is 10^a[i]
        // Max number of banknotes we can use from this denomination
        long long max_banknotes = k - banknotes_used;
        
        if (max_banknotes <= 0) {
            break;
        }
        
        long long max_value_with_this_denomination = denomination * max_banknotes;
        current_sum += max_value_with_this_denomination;
        banknotes_used += max_banknotes;
    }

    return current_sum + 1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << find_min_burles(n, k, a) << endl;
    }
    
    return 0;
}

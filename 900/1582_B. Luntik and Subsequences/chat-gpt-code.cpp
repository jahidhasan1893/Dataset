#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countNearlyFullSubsequences(const vector<int>& a) {
    int n = a.size();
    long long s = 0;
    for (int num : a) {
        s += num;
    }

    // We need to find subsequences whose sum is s - 1
    long long target = s - 1;
    
    // Use a dynamic programming approach to count subsequences with specific sums
    unordered_map<long long, long long> dp;
    dp[0] = 1; // there's always 1 way to get a sum of 0 (the empty subsequence)

    for (int num : a) {
        // Traverse dp in reverse order to prevent overwriting
        vector<pair<long long, long long>> updates;
        for (auto& entry : dp) {
            long long current_sum = entry.first;
            long long count = entry.second;
            updates.push_back({current_sum + num, count});
        }

        for (auto& update : updates) {
            dp[update.first] += update.second;
        }
    }

    // Return the number of subsequences that sum to s - 1
    return dp[target];
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

        // Compute and print the result for the current test case
        cout << countNearlyFullSubsequences(a) << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to calculate n choose 3 (combinatorics)
long long nCr3(long long n) {
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> problems(n);
        unordered_map<int, int> topicCount, difficultyCount;

        for (int i = 0; i < n; i++) {
            int topic, difficulty;
            cin >> topic >> difficulty;
            problems[i] = {topic, difficulty};
            topicCount[topic]++;
            difficultyCount[difficulty]++;
        }

        // Total number of ways to select 3 problems from n
        long long totalWays = nCr3(n);

        // Count invalid triplets where 3 problems have the same topic
        long long invalidByTopic = 0;
        for (const auto& entry : topicCount) {
            invalidByTopic += nCr3(entry.second);
        }

        // Count invalid triplets where 3 problems have the same difficulty
        long long invalidByDifficulty = 0;
        for (const auto& entry : difficultyCount) {
            invalidByDifficulty += nCr3(entry.second);
        }

        // The valid triplets are those that are total ways minus invalid triplets
        long long validWays = totalWays - invalidByTopic - invalidByDifficulty;

        cout << validWays << '\n';
    }

    return 0;
}

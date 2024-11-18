#include <iostream>
#include <vector>

#define MOD 1000000007

// Transition matrix for valid colorings based on the restrictions
// Colors are indexed as follows:
// 0 - White, 1 - Green, 2 - Red, 3 - Blue, 4 - Orange, 5 - Yellow
int adj[6][6] = {
    {0, 1, 1, 1, 1, 0}, // White: can't be adjacent to White or Yellow
    {1, 0, 1, 1, 1, 1}, // Green: can't be adjacent to Green or Blue
    {1, 1, 0, 1, 1, 1}, // Red: can't be adjacent to Red or Orange
    {1, 1, 1, 0, 1, 1}, // Blue: can't be adjacent to Green or Blue
    {1, 1, 1, 1, 0, 1}, // Orange: can't be adjacent to Red or Orange
    {0, 1, 1, 1, 1, 0}  // Yellow: can't be adjacent to White or Yellow
};

// Recursive function to compute the number of good colorings
int countColorings(int k) {
    // The number of valid colorings for a perfect binary tree of height k
    // dp[h][color] means the number of colorings of a subtree of height h
    // where the root is colored 'color'
    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(6, 0));

    // Base case: At height 0 (leaf node), there are 6 possibilities (one for each color)
    for (int color = 0; color < 6; ++color) {
        dp[0][color] = 1;  // Leaf nodes can be any color
    }

    // Fill DP for larger subtrees
    for (int h = 1; h <= k; ++h) {
        for (int color = 0; color < 6; ++color) {
            // For each color of the current root, consider the colorings of the left and right children
            dp[h][color] = 0;
            for (int leftColor = 0; leftColor < 6; ++leftColor) {
                for (int rightColor = 0; rightColor < 6; ++rightColor) {
                    if (adj[color][leftColor] && adj[color][rightColor]) {
                        dp[h][color] = (dp[h][color] + dp[h-1][leftColor] * dp[h-1][rightColor]) % MOD;
                    }
                }
            }
        }
    }

    // The answer is the sum of all colorings of the root node at height k
    int result = 0;
    for (int color = 0; color < 6; ++color) {
        result = (result + dp[k][color]) % MOD;
    }

    return result;
}

int main() {
    int k;
    std::cin >> k;

    std::cout << countColorings(k) << std::endl;

    return 0;
}

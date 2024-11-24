#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of operations needed to make a portal
int min_operations_to_make_portal(int n, int m, const vector<string>& grid, int a, int b) {
    int min_operations = INT_MAX;

    // Traverse all possible top-left corners of a subrectangle of size a x b
    for (int i = 0; i <= n - a; ++i) {
        for (int j = 0; j <= m - b; ++j) {
            int operations = 0;

            // Check the perimeter of the portal (excluding corners)
            // Top row (except the corners)
            for (int col = j + 1; col < j + b - 1; ++col) {
                if (grid[i][col] != '1') operations++;
            }
            // Bottom row (except the corners)
            for (int col = j + 1; col < j + b - 1; ++col) {
                if (grid[i + a - 1][col] != '1') operations++;
            }
            // Left column (except the corners)
            for (int row = i + 1; row < i + a - 1; ++row) {
                if (grid[row][j] != '1') operations++;
            }
            // Right column (except the corners)
            for (int row = i + 1; row < i + a - 1; ++row) {
                if (grid[row][j + b - 1] != '1') operations++;
            }

            // Check the interior (everything should be 0)
            for (int row = i + 1; row < i + a - 1; ++row) {
                for (int col = j + 1; col < j + b - 1; ++col) {
                    if (grid[row][col] != '0') operations++;
                }
            }

            // Update the minimum operations required
            min_operations = min(min_operations, operations);
        }
    }

    return min_operations == INT_MAX ? -1 : min_operations;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int result = INT_MAX;

        // Try all portal sizes a >= 5 and b >= 4
        for (int a = 5; a <= n; ++a) {
            for (int b = 4; b <= m; ++b) {
                int ops = min_operations_to_make_portal(n, m, grid, a, b);
                if (ops != -1) {
                    result = min(result, ops);
                }
            }
        }

        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}

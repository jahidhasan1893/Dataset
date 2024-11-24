#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000; // max n (rows) and m (columns)
int n, m;
vector<string> grid;
vector<vector<bool>> exitable;

// Preprocess grid to determine exitable cells
void preprocess() {
    exitable.assign(n, vector<bool>(m, false));

    // Mark the first row and first column as exitable if empty
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == '.') exitable[i][0] = true;
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == '.') exitable[0][j] = true;
    }

    // Propagate exitable information through the grid
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '.' && (exitable[i-1][j] || exitable[i][j-1])) {
                exitable[i][j] = true;
            }
        }
    }
}

// Check if subgrid [x1, x2] is determinable
bool is_determinable(int x1, int x2) {
    for (int i = 0; i < n; i++) {
        bool found_exitable = false;
        bool has_filled = false;

        // Check each row in the subgrid from x1 to x2
        for (int j = x1; j <= x2; j++) {
            if (exitable[i][j]) {
                if (has_filled) return false; // if after a filled, there's an exitable
                found_exitable = true;
            } else {
                has_filled = true; // a filled cell encountered
            }
        }

        // If there is any exitable cell, they should form a contiguous block
        if (found_exitable && !has_filled) {
            // Check if it's a valid segment: all exitable cells must form a contiguous block
            bool exitable_found = false;
            for (int j = x1; j <= x2; j++) {
                if (exitable[i][j]) {
                    if (exitable_found && !exitable[i][j]) return false; // break in contiguous block
                    exitable_found = true;
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read grid dimensions and grid itself
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Preprocess to determine exitable cells
    preprocess();

    // Number of queries
    int q;
    cin >> q;

    // Process each query
    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--; x2--;  // Convert to 0-based indexing

        // Answer query
        if (is_determinable(x1, x2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

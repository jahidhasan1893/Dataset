#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceTick(const vector<string>& grid, int n, int m, int i, int j, int d) {
    // Check if a tick of size d can be placed centered at (i, j)
    if (i - d < 0 || i + d >= n || j - d < 0 || j + d >= m) {
        return false;
    }
    
    // Check the cells that would be part of the tick
    for (int h = 0; h <= d; ++h) {
        if (grid[i - h][j - h] != '*' || grid[i - h][j + h] != '*') {
            return false;
        }
    }
    
    return true;
}

void markTick(vector<string>& grid, int n, int m, int i, int j, int d) {
    // Mark the tick as processed by setting those cells to '.'
    for (int h = 0; h <= d; ++h) {
        grid[i - h][j - h] = '.';
        grid[i - h][j + h] = '.';
    }
    grid[i][j] = '.';
}

bool isValidTickField(const vector<string>& grid, int n, int m, int k) {
    // Create a mutable copy of the grid to modify during processing
    vector<string> gridCopy = grid;
    
    // Try to find and validate ticks
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (gridCopy[i][j] == '*') {
                // Try to place the largest tick at (i, j)
                int maxSize = 0;
                while (canPlaceTick(gridCopy, n, m, i, j, maxSize + 1)) {
                    maxSize++;
                }
                if (maxSize >= k) {
                    // Mark the tick of size maxSize
                    markTick(gridCopy, n, m, i, j, maxSize);
                } else {
                    // If the '*' can't be part of a valid tick of size >= k
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        if (isValidTickField(grid, n, m, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

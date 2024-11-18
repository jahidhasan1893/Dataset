#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> grid(n, vector<int>(m));
    
    // Read the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Read the starting columns for the balls
    vector<int> balls(k);
    for (int i = 0; i < k; ++i) {
        cin >> balls[i];
        balls[i]--;  // Convert to 0-based index
    }
    
    // Process each ball
    for (int ball : balls) {
        int col = ball; // Start column (0-based)
        int row = 0;    // Start from the first row
        
        while (row < n) {
            if (grid[row][col] == 1) {  // Move right
                if (col + 1 < m && grid[row][col + 1] != 3) {
                    col++;  // Move to the right
                } else {
                    break;  // Ball is stuck (blocked on the right)
                }
            } else if (grid[row][col] == 2) {  // Move down
                row++;  // Move down
            } else if (grid[row][col] == 3) {  // Move left
                if (col - 1 >= 0 && grid[row][col - 1] != 1) {
                    col--;  // Move to the left
                } else {
                    break;  // Ball is stuck (blocked on the left)
                }
            }
            // Once the ball leaves the cell, mark it as a "downward" move
            grid[row][col] = 2;
        }
        
        // Output the result (convert to 1-based column index)
        cout << col + 1 << " ";
    }
    cout << endl;
    
    return 0;
}

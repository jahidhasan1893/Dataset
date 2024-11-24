#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // up, down, left, right
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // top-left, top-right, bottom-left, bottom-right
};

bool isValid(int x, int y, int n, const vector<string>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < 2 && y >= 0 && y < n && grid[x][y] == '0' && !visited[x][y];
}

bool canReach(int n, const vector<string>& grid) {
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    queue<pair<int, int>> q;
    
    // Start from (1, 1)
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        // If we've reached (2, n) (i.e., grid[1][n-1]), return true
        if (x == 1 && y == n - 1) {
            return true;
        }
        
        // Explore all 8 possible directions
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            
            if (isValid(nx, ny, n, grid, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    // If we exhaust the queue without reaching (2, n), return false
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(2);
        cin >> grid[0];
        cin >> grid[1];
        
        if (canReach(n, grid)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

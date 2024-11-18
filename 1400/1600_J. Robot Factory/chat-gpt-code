#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Directions: North, East, South, West
const int dx[4] = {-1, 0, 1, 0}; // row movement
const int dy[4] = {0, 1, 0, -1}; // column movement

// Wall positions corresponding to North, East, South, West
const int WALL_MASK[4] = {8, 4, 2, 1}; // North=8, East=4, South=2, West=1

// Check if there's a wall between two adjacent tiles
bool has_wall(int tile1, int tile2, int direction) {
    if (direction == 0) { // North: Tile1's North and Tile2's South
        return (tile1 & WALL_MASK[0]) > 0 || (tile2 & WALL_MASK[2]) > 0;
    }
    if (direction == 1) { // East: Tile1's East and Tile2's West
        return (tile1 & WALL_MASK[1]) > 0 || (tile2 & WALL_MASK[3]) > 0;
    }
    if (direction == 2) { // South: Tile1's South and Tile2's North
        return (tile1 & WALL_MASK[2]) > 0 || (tile2 & WALL_MASK[0]) > 0;
    }
    if (direction == 3) { // West: Tile1's West and Tile2's East
        return (tile1 & WALL_MASK[3]) > 0 || (tile2 & WALL_MASK[1]) > 0;
    }
    return false;
}

// DFS to explore a room starting from (x, y)
void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m) {
    stack<pair<int, int>> stk;
    stk.push({x, y});
    visited[x][y] = true;
    
    while (!stk.empty()) {
        auto [cx, cy] = stk.top();
        stk.pop();
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                // Check if there's no wall between (cx, cy) and (nx, ny)
                if (!has_wall(grid[cx][cy], grid[nx][ny], dir)) {
                    visited[nx][ny] = true;
                    stk.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> room_sizes;
    
    // Find all rooms
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                int initial_size = 0;
                stack<pair<int, int>> stk;
                stk.push({i, j});
                visited[i][j] = true;
                
                // DFS to find the size of the current room
                while (!stk.empty()) {
                    auto [cx, cy] = stk.top();
                    stk.pop();
                    initial_size++;
                    
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cx + dx[dir], ny = cy + dy[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                            // Check if there's no wall between (cx, cy) and (nx, ny)
                            if (!has_wall(grid[cx][cy], grid[nx][ny], dir)) {
                                visited[nx][ny] = true;
                                stk.push({nx, ny});
                            }
                        }
                    }
                }
                room_sizes.push_back(initial_size);
            }
        }
    }
    
    // Sort room sizes in descending order
    sort(room_sizes.begin(), room_sizes.end(), greater<int>());
    
    // Output the room sizes
    for (int size : room_sizes) {
        cout << size << " ";
    }
    cout << endl;
    
    return 0;
}

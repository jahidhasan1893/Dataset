#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // BFS setup
    queue<int> q;
    vector<int> dist(n + 1, -1);  // dist[i] will hold the minimum jumps to reach position i
    vector<int> parent(n + 1, -1); // parent[i] will help to reconstruct the path
    
    // Start BFS from the bottom of the well (n meters)
    dist[n] = 0;
    q.push(n);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Try to jump to every position from current - a[current] to current
        for (int i = current - a[current]; i <= current; ++i) {
            if (i >= 0 && dist[i] == -1) { // Not visited
                dist[i] = dist[current] + 1;
                parent[i] = current;
                q.push(i);
            }
        }
    }

    // If we cannot reach ground (position 0), print -1
    if (dist[0] == -1) {
        cout << -1 << endl;
        return 0;
    }
    
    // Otherwise, reconstruct the path from 0 to n
    vector<int> path;
    int current = 0;
    while (current != n) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(n);
    
    // Since we've been constructing the path from 0 to n, reverse it to print from n to 0
    reverse(path.begin(), path.end());
    
    // Output the result
    cout << dist[0] << endl;
    for (int i = 0; i < dist[0]; ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}

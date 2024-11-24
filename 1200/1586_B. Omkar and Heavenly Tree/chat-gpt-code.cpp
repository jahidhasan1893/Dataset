#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        int n, m;
        cin >> n >> m;  // Read the number of nodes and the number of restrictions
        
        // Skip the m restrictions as we don't need to process them for this approach
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
        }
        
        // Output the tree in a star shape: all nodes connected to node 1
        for (int i = 2; i <= n; i++) {
            cout << 1 << " " << i << endl;
        }
    }
    
    return 0;
}

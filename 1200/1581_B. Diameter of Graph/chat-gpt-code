#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        if (n == 1) {
            cout << "YES" << endl;
        }
        else if (m < n - 1) {
            cout << "NO" << endl;
        }
        else {
            // The max number of edges in a graph with diameter < k-1
            long long max_edges = (k - 2) * (n - 1);
            
            if (m <= max_edges) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

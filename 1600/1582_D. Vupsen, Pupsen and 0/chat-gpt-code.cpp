#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Constructing array b such that the dot product is zero
        for (int i = 0; i < n; i++) {
            // Alternate between 1 and -1 for b
            b[i] = (i % 2 == 0) ? 1 : -1;
        }
        
        // Output the array b
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

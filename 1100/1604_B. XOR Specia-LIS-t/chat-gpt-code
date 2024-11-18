#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int cnt = 0;
        // Check the number of drops where a[i] > a[i+1]
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                cnt++;
            }
        }
        
        // If the number of drops is even, it's possible to split the array
        if (cnt % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

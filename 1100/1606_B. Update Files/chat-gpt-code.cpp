#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // If k >= n, we can distribute updates in 1 hour
        if (k >= n) {
            cout << 1 << endl;
            continue;
        }
        
        // If k == 1, it will take n-1 hours since we can only update one computer at a time
        if (k == 1) {
            cout << n - 1 << endl;
            continue;
        }
        
        long long updated_computers = 1;  // Initially only the first computer has the update
        long long hours = 0;
        
        while (updated_computers < n) {
            hours++;
            updated_computers += k * hours;  // Add up to k * hours more computers that can get the update
        }
        
        cout << hours << endl;
    }
    
    return 0;
}

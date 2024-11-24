#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Read the number of students
        
        vector<vector<int>> availability(n, vector<int>(5));  // n students, 5 days
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> availability[i][j];  // Read the availability of the i-th student
            }
        }
        
        bool possible = false;
        
        // Try all pairs of distinct days (d1, d2) where 1 <= d1 < d2 <= 5
        for (int d1 = 0; d1 < 5; ++d1) {
            for (int d2 = d1 + 1; d2 < 5; ++d2) {
                int group1 = 0, group2 = 0;
                
                // Count how many students are available for both days
                for (int i = 0; i < n; ++i) {
                    if (availability[i][d1] == 1 && availability[i][d2] == 0) {
                        group1++;
                    } else if (availability[i][d1] == 0 && availability[i][d2] == 1) {
                        group2++;
                    }
                }
                
                // Check if it's possible to divide the students into two equal groups
                if (group1 == group2 && group1 == n / 2) {
                    possible = true;
                    break;
                }
            }
            
            if (possible) {
                break;
            }
        }
        
        // Output the result for the current test case
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

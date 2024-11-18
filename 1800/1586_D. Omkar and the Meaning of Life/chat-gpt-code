#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);  // This will store the permutation (to be filled)
    
    // We will perform n queries, each querying a sequence of length n
    // We can choose a simple strategy like querying for [1, 1, ..., 1]
    
    vector<int> a(n, 1); // Start with a query where all elements are 1
    
    for (int i = 0; i < n; ++i) {
        // Query format
        cout << "? ";
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
        cout.flush();  // Make sure to flush the output after each query
        
        int k;
        cin >> k;
        
        if (k == 0) {
            // No duplicates found
            // This means s_j = p_j + 1 has no repeats, which gives us no direct info
        } else {
            // A repeated value is found, meaning s[k] occurs more than once
            // This gives us some clues about the value of p[k] and the permutation
        }
        
        // We will need to interpret these results and use the feedback to update our guess.
        // Eventually output the found permutation.
    }

    // Output the final permutation after we've deduced it
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}

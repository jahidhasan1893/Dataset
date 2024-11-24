#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // To store all distinct XOR values
    set<int> possibleXORs;
    
    // Start with the empty subsequence, which has XOR = 0
    possibleXORs.insert(0);
    
    // For each element in the array, update the possible XOR values
    for (int i = 0; i < n; i++) {
        // Temporary set to store new XORs generated by including a[i]
        set<int> newXORs = possibleXORs; // Copy current set
        for (int x : possibleXORs) {
            newXORs.insert(x ^ a[i]); // XOR with current element a[i]
        }
        // Update the possible XORs set
        possibleXORs = newXORs;
    }
    
    // Convert the set to a sorted vector
    vector<int> result(possibleXORs.begin(), possibleXORs.end());
    
    // Output the results
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
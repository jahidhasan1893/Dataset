#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    int last_taken = -1;  // Initialize to a number less than any element in the array
    int turn_count = 0;   // Count how many valid moves are made

    while (l <= r) {
        if (a[l] > last_taken && a[r] > last_taken) {
            // If both ends are valid, take the larger one
            if (a[l] > a[r]) {
                last_taken = a[l++];
            } else {
                last_taken = a[r--];
            }
        } else if (a[l] > last_taken) {
            last_taken = a[l++];
        } else if (a[r] > last_taken) {
            last_taken = a[r--];
        } else {
            break;  // No more valid moves
        }

        turn_count++;  // Increment turn count after each valid move
    }

    // If the number of moves is odd, Alice wins (since she starts first), otherwise Bob wins
    if (turn_count % 2 == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}

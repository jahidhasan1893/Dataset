#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count inversions in the deque
int count_inversions(const deque<int>& dq) {
    int inv = 0;
    for (int i = 0; i < dq.size(); i++) {
        for (int j = i + 1; j < dq.size(); j++) {
            if (dq[i] > dq[j]) {
                inv++;
            }
        }
    }
    return inv;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        deque<int> dq;
        dq.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] < dq.front()) {
                dq.push_front(a[i]);
            } else {
                dq.push_back(a[i]);
            }
        }

        // After constructing the deque, count inversions
        cout << count_inversions(dq) << endl;
    }
}

int main() {
    solve();
    return 0;
}

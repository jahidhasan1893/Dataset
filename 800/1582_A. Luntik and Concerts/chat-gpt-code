#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;  // Number of 1-minute, 2-minute, and 3-minute songs

        // Total duration of all songs
        int total_duration = a + 2 * b + 3 * c;

        // The target duration for each concert (aim for half the total duration)
        int target = total_duration / 2;

        // Try to distribute the songs as evenly as possible
        int diff = abs(target - (a + 2 * b + 3 * c) / 2);

        // Output the minimal difference
        cout << diff << endl;
    }

    return 0;
}

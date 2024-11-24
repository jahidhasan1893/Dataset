#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases

    while (t--) {
        int n;
        cin >> n;  // Read number of days
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Read watering schedule (0 or 1)
        }

        int height = 1;  // Initial height of the flower
        bool flowerDied = false;  // Flag to track if the flower dies

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {  // Flower is watered on day i
                if (i > 0 && a[i-1] == 1) {  // Watered on two consecutive days
                    height += 5;  // Growth is 5 cm
                } else {
                    height += 1;  // Growth is 1 cm
                }
            }

            // Check if the flower dies (two consecutive days of no watering)
            if (i > 0 && a[i] == 0 && a[i-1] == 0) {
                flowerDied = true;
                break;  // Flower dies, no need to check further days
            }
        }

        if (flowerDied) {
            cout << -1 << endl;  // The flower died
        } else {
            cout << height << endl;  // Output the final height of the flower
        }
    }

    return 0;
}

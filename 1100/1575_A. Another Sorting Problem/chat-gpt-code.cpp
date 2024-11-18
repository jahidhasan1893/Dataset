#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // Read the number of books and the length of each book title

    vector<pair<string, int>> books(n);  // To store the book titles and their original indices
    for (int i = 0; i < n; ++i) {
        cin >> books[i].first;  // Read each book title
        books[i].second = i + 1;  // Store the original index (1-based)
    }

    // We need to sort based on the custom lexicographical rules for each title
    auto compare = [&](const pair<string, int>& a, const pair<string, int>& b) {
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                // Odd indexed characters (1st, 3rd, 5th...) -> ascending order
                if (a.first[i] != b.first[i]) {
                    return a.first[i] < b.first[i];  // Compare lexicographically ascending
                }
            } else {
                // Even indexed characters (2nd, 4th, 6th...) -> descending order
                if (a.first[i] != b.first[i]) {
                    return a.first[i] > b.first[i];  // Compare lexicographically descending
                }
            }
        }
        return false;  // If they are identical, we don't need to change their order
    };

    // Sort the books according to the compare function
    sort(books.begin(), books.end(), compare);

    // Output the original indices of the sorted books
    for (const auto& book : books) {
        cout << book.second << " ";  // Output the original index of the book
    }
    cout << endl;

    return 0;
}

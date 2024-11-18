#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Person {
    int sociability;
    int index;
    
    bool operator<(const Person& other) const {
        // We want a max-heap based on sociability (largest sociability first)
        return sociability < other.sociability;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> sociability(n);
        for (int i = 0; i < n; ++i) {
            cin >> sociability[i];
        }
        
        // Max-heap to store the people by their sociability
        priority_queue<Person> pq;
        
        // Populate the priority queue
        for (int i = 0; i < n; ++i) {
            if (sociability[i] > 0) {
                pq.push({sociability[i], i + 1}); // (sociability, person index)
            }
        }
        
        vector<pair<int, int>> talks;
        
        // While there are at least two people with sociability > 0
        while (pq.size() > 1) {
            // Take the two people with the highest sociability
            Person p1 = pq.top(); pq.pop();
            Person p2 = pq.top(); pq.pop();
            
            // Record this talk
            talks.push_back({p1.index, p2.index});
            
            // Decrease their sociability
            if (--p1.sociability > 0) {
                pq.push(p1); // reinsert if still has sociability left
            }
            if (--p2.sociability > 0) {
                pq.push(p2); // reinsert if still has sociability left
            }
        }
        
        // Output the number of talks
        cout << talks.size() << endl;
        for (const auto& talk : talks) {
            cout << talk.first << " " << talk.second << endl;
        }
    }
    
    return 0;
}

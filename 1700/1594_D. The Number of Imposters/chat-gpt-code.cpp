#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), size(n, 1), parity(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            int root = find(parent[x]);
            parity[x] ^= parity[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y, int relation) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return parity[x] ^ parity[y] == relation;
        }
        
        parent[rootY] = rootX;
        parity[rootY] = parity[x] ^ parity[y] ^ relation;
        size[rootX] += size[rootY];
        return true;
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
    
private:
    vector<int> parent;
    vector<int> size;
    vector<int> parity;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        UnionFind uf(n);
        bool isValid = true;
        
        while (m--) {
            int i, j;
            string c;
            cin >> i >> j >> c;
            --i, --j;  // 0-based index
            
            int relation = (c == "crewmate" ? 0 : 1);  // 0: same, 1: opposite
            if (!uf.unionSets(i, j, relation)) {
                isValid = false;
                break;
            }
        }
        
        if (!isValid) {
            cout << "-1\n";
            continue;
        }
        
        // Count the size of each component
        vector<int> groupSize(n, 0);
        for (int i = 0; i < n; ++i) {
            groupSize[uf.find(i)]++;
        }
        
        // Calculate the maximum number of imposters
        int maxImposters = 0;
        for (int i = 0; i < n; ++i) {
            if (uf.find(i) == i) {
                int group1 = groupSize[i];  // crewmates
                int group2 = n - group1;    // imposters
                maxImposters += min(group1, group2);  // maximize imposters
            }
        }
        
        cout << maxImposters << "\n";
    }
    
    return 0;
}

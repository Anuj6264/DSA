#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public: 
    vector<int>parent, size;

    DisjointSet (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    //Find ultimate parent : Time Complexity -> O(4 alpha) ~ O(1) 
    int findUParent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int upu = findUParent(u);
        int upv = findUParent(v);
        if(upu == upv)
            return;
        if(size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if(ds.findUParent(3) == ds.findUParent(7))
        cout << "Same parent" << endl;
    else
        cout << "Not same parent" << endl;
    ds.unionBySize(3, 7);
     if(ds.findUParent(3) == ds.findUParent(7))
        cout << "Same parent" << endl;
    else
        cout << "Not same parent" << endl;

    return 0;

}
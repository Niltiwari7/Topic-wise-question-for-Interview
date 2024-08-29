class DSU {
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findP(int u) {
        if (parent[u] == u) {
            return parent[u];
        }
        return parent[u] = findP(parent[u]);
    }

    void Union(int u, int v) {
        int u_par = findP(u);
        int v_par = findP(v);
        if (u_par == v_par) {
            return;
        }
        if (rank[u_par] < rank[v_par]) {
            parent[v_par] = u_par;
        } else if (rank[u_par] > rank[v_par]) {
            parent[u_par] = v_par;
        } else {
            parent[u_par] = v_par;
            rank[u_par]++;
        }
    }
};
class Solution {
public:
    bool isValid(vector<int>& v1, vector<int>& v2) {
        return v1[0] == v2[0] || v1[1] == v2[1];
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        int comp = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int u_par = dsu.findP(i);
                int v_par = dsu.findP(j);
                if (isValid(stones[i], stones[j])) {
                    if (u_par != v_par) {
                        comp--;
                        dsu.Union(i, j);
                    }
                }
            }
        }
        return n - comp;
    }
};
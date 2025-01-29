class Solution {
public:
    bool isConnected(int src, int tar, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;
        if (src == tar) {
            return true;
        }

        for (auto ngbr : adj[src]) {
            if (!vis[ngbr]) {
                if (isConnected(ngbr, tar, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto e : edges) {
            vector<bool> vis(n + 1, false); 
            if (isConnected(e[0] - 1, e[1] - 1, adj, vis)) {
                return e;  
            }
            adj[e[0] - 1].push_back(e[1] - 1); 
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        return {};  // In case no redundant connection is found (shouldn't happen)
    }
};

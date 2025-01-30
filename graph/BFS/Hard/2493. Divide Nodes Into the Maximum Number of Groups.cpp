class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>>& adj, int curr,
                     vector<int>& colors, int currColor) {
        if (colors[curr] != -1) return colors[curr] == currColor;
        colors[curr] = currColor;
        
        for (int& ngbr : adj[curr]) {
            if (!isBipartite(adj, ngbr, colors, 1 - currColor)) {
                return false;
            }
        }
        return true;
    }

    int BFS(int node, unordered_map<int, vector<int>>& adj, int n) {
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({node, 0});
        vis[node] = true;
        int maxi = 0;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            maxi = max(maxi, dist);

            for (auto& ngbr : adj[curr]) {
                if (!vis[ngbr]) {
                    q.push({ngbr, dist + 1});
                    vis[ngbr] = true;
                }
            }
        }
        return maxi+1;
    }

    int getmax(int node, unordered_map<int, vector<int>>& adj,
               vector<bool>& vis, vector<int>& level) {
        int maxGrp = level[node];
        vis[node] = true;

        for (auto curr : adj[node]) {
            if (!vis[curr]) {
                maxGrp = max(maxGrp, getmax(curr, adj, vis, level));
            }
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);
        for (int node = 0; node < n; node++) {
            if (color[node] == -1 && !isBipartite(adj, node, color, 1)) {
                return -1;
            }
        }

        vector<int> level(n, 0);
        for (int node = 0; node < n; node++) {
            level[node] = BFS(node, adj, n);
        }

        vector<bool> vis(n, false);
        long long res = 0;
        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                res += getmax(node, adj, vis, level);
            }
        }
        return res;
    }
};

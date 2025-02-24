class Solution {
    public:
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> mp;
        int result = INT_MIN;
    
        bool BobDFS(int curr, int t, vector<bool>& vis) {
            vis[curr] = true;
            mp[curr] = t;
            if (curr == 0) {
                return true;
            }
            for (auto& ngbr : adj[curr]) {
                if (!vis[ngbr]) {
                    if (BobDFS(ngbr, t + 1, vis) == true) {
                        return true;
                    }
                }
            }
    
            mp.erase(curr);
            return false;
        }
    
        void DFS(int curr, int t, int income, vector<bool>& vis,
                 vector<int>& amount) {
            vis[curr] = true;
            if (mp.find(curr) == mp.end() || t < mp[curr]) {
                income += amount[curr];
            } else if (t == mp[curr]) {
                income += (amount[curr] / 2);
            }
    
            if (adj[curr].size() == 1 && curr!=0) {
                result = max(result, income);
            }
    
            for (auto& ngbr : adj[curr]) {
                if (!vis[ngbr]) {
                    DFS(ngbr, t + 1, income, vis, amount);
                }
            }
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob,
                               vector<int>& amount) {
    
            for (auto ele : edges) {
                int u = ele[0];
                int v = ele[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            unordered_map<int, int> mp;
            int time = 0;
            int n = amount.size();
            vector<bool> vis(n, false);
            BobDFS(bob, time, vis);
            vis.assign(n, false);
            int income = 0;
            DFS(0, 0, income, vis, amount);
            return result;
        }
    };
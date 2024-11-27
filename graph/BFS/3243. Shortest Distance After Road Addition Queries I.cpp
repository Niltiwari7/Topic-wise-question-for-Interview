// Time Complexity - O(q*(V+E))
class Solution {
public:
    int shortest_dist(int node, unordered_map<int, vector<int>> &mp,
                      int target) {
        queue<int> q;
        q.push(node);
        unordered_set<int> vis;
        vis.insert(node);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                auto curr = q.front();
                if (curr == target) {
                    return level;
                }
                q.pop();
                for (auto it : mp[curr]) {

                    if (vis.find(it) == vis.end()) {
                        q.push(it);
                        vis.insert(it);
                    }
                }
            }
            level++;
        }
        return level;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        for (auto q : queries) {
            int u = q[0];
            int v = q[1];
            adj[u].push_back(v);
            int dist = shortest_dist(0, adj, n - 1);
            res.push_back(dist);
        }
        return res;
    }
};
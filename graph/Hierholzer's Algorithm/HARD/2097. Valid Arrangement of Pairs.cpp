class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& path) {
        while (!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back(); // Remove edge after visiting
            dfs(next, adj, path);
        }
        path.push_back(node); // Add to path after all edges from this node are processed
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // Build adjacency list and track in-degrees and out-degrees
        for (auto& p : pairs) {
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // Find start node for Eulerian path
        int startNode = pairs[0][0]; // Default start node
        for (auto& it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        // Perform DFS to construct Eulerian path
        vector<int> path;
        dfs(startNode, adj, path);
        reverse(path.begin(), path.end()); // Reverse the path to get the correct order

        // Convert path to pairs for output
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};

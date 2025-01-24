class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& graph, vector<bool>& vis,
                 vector<bool>& inRecursion) {
        inRecursion[node] = true;
        vis[node] = true;
        for (auto& v : graph[node]) {
            if (!vis[v] && isCycle(v, graph, vis, inRecursion)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }
        inRecursion[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> inRecursion(V, false);
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                isCycle(i, graph, vis, inRecursion);
            }
        }

        for (int i = 0; i < V; i++) {
            if (!inRecursion[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// Topological sort
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (int& v : graph[u]) {
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        vector<bool> vis(V, false);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            vis[node] = true;
            for (auto& v : adj[node]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (vis[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
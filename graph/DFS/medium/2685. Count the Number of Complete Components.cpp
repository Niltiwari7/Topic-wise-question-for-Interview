class Solution {
    public:
        void DFS(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis, vector<int>& component) {
            vis[node] = true;
            component.push_back(node);
            
            for (auto ngbr : adj[node]) {
                if (!vis[ngbr]) {
                    DFS(ngbr, adj, vis, component);
                }
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> adj;
            
            // Build adjacency list
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<bool> vis(n, false);
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vector<int> component;
                    DFS(i, adj, vis, component);
    
                    // Check if the component is complete
                    bool isComplete = true;
                    int size = component.size();
                    for (int node : component) {
                        if (adj[node].size() != size - 1) { 
                            isComplete = false;
                            break;
                        }
                    }
    
                    if (isComplete) count++;
                }
            }
            return count;
        }
    };
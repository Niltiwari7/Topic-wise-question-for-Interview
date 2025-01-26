class Solution {
public:
    int BFS(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        int res = 0;
        queue<pair<int,int>> q;
        q.push({node,0});
        vis[node] = true;

        while (!q.empty()) {
            auto[curr,dist] = q.front();
            q.pop();
           
            for (auto neigh : adj[curr]) {
                if (!vis[neigh]) {
                    q.push({neigh,dist+1});
                    res = max(res,dist+1);
                    vis[neigh] = true;
                }
            }
        }

        return res;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        // Create the reverse adjacency list
        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        int longestCycle = 0;  // For storing the longest cycle
        int happyCoupleCount = 0;  // To store the contribution of happy couples
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> mp;  // Map to detect cycles
                int currNode = i;
                int currNodeCount = 0;

                // Detect cycle
                while (!vis[currNode]) {
                    vis[currNode] = true;
                    mp[currNode] = currNodeCount;
                    currNodeCount++;
                    int nextNode = favorite[currNode];

                    // If a cycle is detected
                    if (mp.count(nextNode)) {
                        int cycleLength = currNodeCount - mp[nextNode];
                        longestCycle = max(longestCycle, cycleLength);

                        // Special case: cycle of length 2 (happy couple)
                        if (cycleLength == 2) {
                            vector<bool> visNode(n, false);
                            visNode[currNode] = true;
                            visNode[nextNode] = true;
                            int extraLength = BFS(currNode, adj, visNode) + 
                                              BFS(nextNode, adj, visNode);
                            happyCoupleCount += extraLength + 2;
                        }

                        break;
                    }

                    currNode = nextNode;
                }
            }
        }

        return max(longestCycle, happyCoupleCount);
    }
};

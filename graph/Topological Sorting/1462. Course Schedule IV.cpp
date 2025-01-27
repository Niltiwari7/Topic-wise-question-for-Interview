// Brute force
class Solution {
public:
    bool BFS(int node, int target, vector<vector<int>>& adj) {
        queue<int> q;
        unordered_set<int> st;
        q.push(node);
        st.insert(node);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr == target) {
                return true;
            }
            for (auto neigh : adj[curr]) {
                if (st.find(neigh) == st.end()) {
                    q.push(neigh);
                    st.insert(neigh);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<bool> result;
        for (auto q : queries) {
            result.push_back(BFS(q[0], q[1], adj));
        }
        return result;
    }
};

// Using Topological Sort
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        unordered_map<int, unordered_set<int>> mp;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& ngbr : adj[node]) {
                mp[ngbr].insert(node);
                for (auto& pre : mp[node]) {
                    mp[ngbr].insert(pre);
                }
                indegree[ngbr]--;
                if (indegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }
        }
        vector<bool> result;
        for (auto q : queries) {
            int src = q[0];
            int dest = q[1];
            bool reachable = mp[dest].contains(src);
            result.push_back(reachable);
        }

        return result;
    }
};
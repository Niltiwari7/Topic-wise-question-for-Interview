class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 2, 0);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            indegree[u]++;
            indegree[v]++;
        }
        for (int i = 1; i <= n + 1; i++) {
            if (indegree[i] == n)
                return i;
        }

        return -1;
    }
};
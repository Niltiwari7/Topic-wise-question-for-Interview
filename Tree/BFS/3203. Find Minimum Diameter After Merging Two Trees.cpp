class Solution {
public:
    int findDiameter(vector<vector<int>>& graph, int curr) {
        queue<int> q;
        q.push(curr);
        unordered_set<int> st;
        st.insert(curr);
        int count = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto node = q.front();
                q.pop();
                for (auto neigh : graph[node]) {
                    if (st.find(neigh) == st.end()) {
                        q.push(neigh);
                        st.insert(neigh);
                    }
                }
            }
            count++;
        }
        return count - 1;
    }
    int get_farthest(vector<vector<int>>& graph) {
        queue<int> q;
        q.push(0);
        int last = -1;
        unordered_set<int> st;
        st.insert(0);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto node = q.front();
                last = node;
                q.pop();
                for (auto neigh : graph[node]) {
                    if (st.find(neigh) == st.end()) {
                        q.push(neigh);
                        st.insert(neigh);
                    }
                }
            }
        }
        return last;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int m = edges1.size();
        int n = edges2.size();
        vector<vector<int>> adj1(m + 1), adj2(n + 1);
        for (auto e : edges1) {
            int u = e[0];
            int v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (auto e : edges2) {
            int u = e[0];
            int v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int lastNode1 = get_farthest(adj1);
        int lastNode2 = get_farthest(adj2);

        int dia1 = findDiameter(adj1, lastNode1);
        int dia2 = findDiameter(adj2, lastNode2);
        return max({dia1, dia2, ((dia1 + 1) / 2) + (dia2 + 1) / 2 + 1});
    }
};
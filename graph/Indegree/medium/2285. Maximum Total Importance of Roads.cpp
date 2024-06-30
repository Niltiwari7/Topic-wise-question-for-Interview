class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> Indegree(n, 0);
        for (auto it : roads) {
            Indegree[it[0]]++;
            Indegree[it[1]]++;
        }

        sort(begin(Indegree), end(Indegree));
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += 1LL*(Indegree[i] * (i + 1));
        }
        return res;
    }
};
class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; }
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> p;
        for (int i = 0; i < profits.size(); i++) {
            p.push_back({profits[i], capital[i]});
        }

        sort(p.begin(), p.end(), comp);

        priority_queue<int> pq;

        int i = 0;
        while (k--) {
            while (i < n && w >= p[i][1]) {
                pq.push(p[i][0]);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
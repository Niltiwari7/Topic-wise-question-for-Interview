class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double wt = 0;
        int s = c[0][0];
        int e = c[0][1] + s;
        int pe = e;
        wt += (e - s);
        int n = c.size();
        for (int i = 1; i < n; i++) {
            s = pe;
            e = max(c[i][1] + s, c[i][0] + c[i][1]);
            pe = e;
            wt += (e - c[i][0]);
        }
        return wt / (n * 1.0);
    }
};
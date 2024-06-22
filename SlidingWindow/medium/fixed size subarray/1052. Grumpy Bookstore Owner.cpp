class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int n = c.size();
        int maxUnstatisfied = 0; // unsatisfied
        int currentUnstatisfied = 0;
        for (int i = 0; i < m; i++) {
            currentUnstatisfied += c[i] * g[i];
        }
        maxUnstatisfied = currentUnstatisfied;
        int i = 0;
        int j = m;

        while (j < n) {
            currentUnstatisfied += c[j] * g[j];
            currentUnstatisfied -= c[i] * g[i];
            maxUnstatisfied = max(maxUnstatisfied, currentUnstatisfied);
            i++;
            j++;
        }
        int totSat = maxUnstatisfied;
        for (int i = 0; i < n; i++) {
            totSat += c[i] * (1 - g[i]);
        }
        return totSat;
    }
};
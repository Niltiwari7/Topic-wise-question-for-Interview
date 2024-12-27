class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxLeft = values[0] + 0;
        int res = 0;
        for (int j = 1; j < values.size(); j++) {
            res = max(res, maxLeft + values[j] - j);
            maxLeft = max(maxLeft, values[j] + j);
        }
        return res;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = INT_MIN;
        int maxVal = arrays[0].back();
        int minVal = arrays[0][0];

        for (int i = 1; i < arrays.size(); ++i) {
            result = max(result, abs(arrays[i][0] - maxVal));
            result = max(result, abs(arrays[i].back() - minVal));
            maxVal = max(maxVal, arrays[i].back());
            minVal = min(minVal, arrays[i][0]);
        }

        return result;
    }
};
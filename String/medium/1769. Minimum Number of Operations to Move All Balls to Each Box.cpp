class Solution {
public:
    int getMove(int idx, string& boxes) {
        int res = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (i == idx) {
                continue;
            }
            if (boxes[i] == '1')
                res += abs(idx - i);
        }
        return res;
    }
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = getMove(i, boxes);
        }
        return ans;
    }
};
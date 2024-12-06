//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                sum += i;
                if (maxSum < sum)
                    break;
                count++;
            }
        }
        return count;
    }
};

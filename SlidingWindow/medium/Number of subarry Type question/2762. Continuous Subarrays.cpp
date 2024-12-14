// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0;
        int j = 0;
        multiset<int> window;
        while (j < nums.size()) {
            window.insert(nums[j]);
            while (abs(*window.rbegin() - *window.begin()) > 2) {
                window.erase(window.find(nums[i]));
                i++;
            }
            res += (j - i + 1);
            j++;
        }
        return res;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0, ans = 0;
        deque<int> maxDeque, minDeque;

        while (j < nums.size()) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[j])
                maxDeque.pop_back();
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[j])
                minDeque.pop_back();

            maxDeque.push_back(j);
            minDeque.push_back(j);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                i++;
                if (maxDeque.front() < i)
                    maxDeque.pop_front();
                if (minDeque.front() < i)
                    minDeque.pop_front();
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0); // Use long long to prevent overflow
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;
        int result = INT_MAX;

        for (int j = 0; j <= n; ++j) {
            // Shrink the window from the front
            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k) {
                result = min(result, j - dq.front());
                dq.pop_front();
            }

            // Maintain deque in increasing order of prefixSum values
            while (!dq.empty() && prefixSum[j] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return result == INT_MAX ? -1 : result;
    }
};

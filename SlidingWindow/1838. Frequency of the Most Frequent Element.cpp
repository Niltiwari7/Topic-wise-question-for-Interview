The frequency of an element is the number of times it occurs in an array.

/*You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 0;
        sort(nums.begin(), nums.end());
        long long result = 0;
        long long ops = 0;
        long long currSum = 0;

        for (int j = 0; j < nums.size(); j++) {
            int target = nums[j];
            currSum += nums[j];
            long long windowSum = 1LL * (j - i + 1) * target;
            ops = windowSum - currSum;

            while (ops > k) {
                currSum -= nums[i];
                i++;
                windowSum = 1LL * (j - i + 1) * nums[j];
                ops = windowSum - currSum;
            }

            result = max<long long>(result, j - i + 1);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int groupNo = 0;
        unordered_map<int, int> numToGroup; 
        unordered_map<int, list<int>> groupToNums; 

        numToGroup[vec[0]] = groupNo;
        groupToNums[groupNo].push_back(vec[0]);

        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNo++; 
            }
            numToGroup[vec[i]] = groupNo;
            groupToNums[groupNo].push_back(vec[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = *(groupToNums[group].begin()); 
            groupToNums[group].pop_front(); 
        }

        return result;
    }
};
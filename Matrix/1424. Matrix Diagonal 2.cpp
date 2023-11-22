/*
Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

Example 1:


Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:


Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey=0;
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey,i+j);
            }
        }
        for(int i=0;i<=maxKey;i++){
            for(auto v:mp[i]){
                ans.push_back(v);
            }
        }
        return ans;
    }
};
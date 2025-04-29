
// LeetCode 2962. Count Subarrays Where Max Element Appears at Least K Times
========================== Brute Force ==========================
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxi_ele = *max_element(begin(nums), end(nums));
            int n = nums.size();
            long long res = 0;
            for (int i = 0; i < nums.size(); i++) {
                int valid = 0;
                for (int j = i; j < nums.size(); j++) {
                    if (nums[j] == maxi_ele)
                        valid++;
                    if (valid >= k)
                        res++;
                }
            }
            return res;
        }
    };

 ================================== Optimized Solution ==========================      
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    long long lessThanK(vector<int>&nums,int k , int &maxi){
        long long ans = 0;
        long long valid = 0;
        for(int i = 0,j=0;j<nums.size();j++){
            if(nums[j]==maxi)valid++;
            while(i<=j && valid>=k){
                if(nums[i++]==maxi)valid--;
            }
            if(valid<k){
                ans+=j-i+1;
            }
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        int maxi = *max_element(begin(nums),end(nums));
        return (n*(n+1))/2 - lessThanK(nums,k,maxi);
    }
};
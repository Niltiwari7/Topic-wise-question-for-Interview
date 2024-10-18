//Brute force problem

class Solution {
public:
    vector<vector<int>>vec;
    void solve(int i,vector<int>&nums,vector<int>&temp){
        if(i>=nums.size()){
            vec.push_back(temp);
            return;
        }
        solve(i+1,nums,temp);
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>temp;
        solve(0,nums,temp);
        int maxi= 0;
        for(auto it:vec){
            int temp = 0;
            for(auto ele:it){
                temp|=ele;
            }
            maxi = max(temp,maxi);
        }
        int count =0;
        for(auto it:vec){
            int temp = 0;
            for(auto ele:it){
                temp|=ele;
            }
            if(temp==maxi){
                count++;
            }
        }
        return count;
    }
};

//Optimize soltuion

class Solution {
public:
    int result = 0;
    void solve(int i ,vector<int>&nums,int maxi,int curr){
        if(i==nums.size()){
            if(maxi == curr){
                ++result;
            }
            return;
        }
        int temp = curr;
        curr|=nums[i];
        solve(i+1,nums,maxi,curr);
        curr = temp;
        solve(i+1,nums,maxi,curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            curr|=nums[i];
            maxi = max(maxi,curr);
        }
        solve(0,nums,maxi,0);
        return result;
    }
};
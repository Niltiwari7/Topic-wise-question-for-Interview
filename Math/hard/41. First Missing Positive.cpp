class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(begin(nums),end(nums));
        unordered_map<int,int>mp;
        bool flag = true;
        for(int i=0;i<nums.size();i++)
        {
             mp[nums[i]]++;
             if(nums[i]==1){
                flag=false;
             }
        }
        if(flag==true)return 1;
           
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0)continue;
            if(mp.find(nums[i]+1)==mp.end()){
               return nums[i]+1;
            }
        }
        return nums[nums.size()-1]+1;
    }
};
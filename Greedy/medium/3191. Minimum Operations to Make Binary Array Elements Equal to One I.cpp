class Solution {
    public:
        int minOperations(vector<int>& nums) {
           int n = nums.size();
            int res = 0;
            for(int i = 0;i<nums.size();i++){
                if(nums[i]==0 && i+2<nums.size()){
                    nums[i] = 1;
                   
                    nums[i+1]= nums[i+1]==0 ? 1:0;
                   
                    nums[i+2] = nums[i+2]==0?1:0;
                    res++;
                }
            }
    
            for(auto it:nums){
                if(it==0){
                    return -1;
                }
            }
            return res;
        }
    };
    
    /*
     
    */
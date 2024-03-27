//Brute force
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long count = 0;
        for(int i = 0;i<nums.size();i++){
            long long prod = nums[i];
            if(prod<k)count++;
            for(int j = i+1;j<nums.size();j++){
                prod*=nums[j]*1LL;
                if(prod<k)count++;
                if(prod>k)break;
            }
        }
        return count;
    }
};


//sliding window approach

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if(k<=1)return 0;
        int prod=1,res=0,left=0;
        for(int right = 0;right<nums.size();right++){
            prod*=nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            res+=right-left+1;
        }
        return res;
    }
};
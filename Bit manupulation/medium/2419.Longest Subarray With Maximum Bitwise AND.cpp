class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int streak = 0;
        int result = 0;
        for(auto &it:nums){
            if(it>maxVal){
                streak = 0;
                 result = 0;
                 maxVal = it;
            }
            if(it==maxVal){
                streak++;
            }else{
                streak = 0;
            }
            result = max(result,streak);

        }
        return result;
    }
};
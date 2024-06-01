class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_s = 0;
        for(auto &num:nums){
            xor_s^=num;
        }
        long long mask = (xor_s)&(-xor_s);
        int groupa = 0;
        int groupb =0;
        for(auto &num:nums){
            if(num&mask){
                groupa^=num;
            }else{
                groupb^=num;
            }
        }
        return {groupa,groupb};
    }
};
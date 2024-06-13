class Solution {
public:
    void sortColors(vector<int>& nums) {
        let cnt0 = 0;
        let cnt1=0;
        let cnt2 = 0;
        for num of nums{
            if(num==0) cnt0++;
            if(num==1)cnt1++;
            if(num==2)cnt2++;
        }
      int j = 0;
      while(cnt0>0){
        nums[j++] = 0;
        cnt0--;
      }
      while(cnt1>0){
        nums[j++] = cnt1;
        cnt1--;
      }

      while(cnt2>0){
        nums[j++] = cnt2++;
        cnt2--;
      }
      return nums;
    }
};
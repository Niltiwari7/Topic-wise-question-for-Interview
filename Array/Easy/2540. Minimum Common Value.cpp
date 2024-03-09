class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      set<int>st(nums2.begin(),nums2.end());
      for(int i= 0;i<nums1.size();i++){
          if(st.find(nums1[i])!=st.end()){
              return nums1[i];
          }
      }  
      return -1;
    }
};
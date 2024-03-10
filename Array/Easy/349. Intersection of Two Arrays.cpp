class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st(nums2.begin(),nums2.end());
        vector<int>ans;

        for(auto ele:nums1){
            if(st.find(ele)!=st.end()){
                ans.push_back(ele);
            }
        }
        set<int>a(ans.begin(),ans.end());
        vector<int>result;
        for(auto it:a){
           result.push_back(it);
        }
        return result;
    }
};
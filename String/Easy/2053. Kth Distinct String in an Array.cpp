class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string>st;
        unordered_map<string,int>mp;
        for(auto it:arr)mp[it]++;
        for(auto &it:arr){
            if(st.find(it)==st.end() && mp[it]==1){
                k--;
                if(k==0){
                    return it;
                }
            }
            st.insert(it);
        }
        return "";
    }
};
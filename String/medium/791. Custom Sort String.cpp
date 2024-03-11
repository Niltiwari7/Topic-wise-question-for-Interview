class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp1;
        for(auto c:s)mp1[c]++;
        string ans = "";
        for(int i = 0;i<order.size();i++){
            if(mp1.find(order[i])!=mp1.end())
             {
               int temp = mp1[order[i]];
               while(temp--) ans+=order[i];
             }
        }
        unordered_map<char,int>mp2;
        for(auto c:order)mp2[c]++;
        for(auto c:s){
            if(mp2.find(c)==mp2.end())ans+=c;
        }

        return ans;
    }
};
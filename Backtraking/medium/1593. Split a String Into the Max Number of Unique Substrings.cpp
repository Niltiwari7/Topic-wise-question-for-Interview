class Solution {
public:
    unordered_set<string>st;
    int ans = 0;
    void solve(int i,string s){
        if(st.size()>ans)ans = st.size();
        if(i>=s.size()){
            return ;
        }
        string str="";
        for(int j = i;j<s.size();j++){
            str+=s[j];
            if(st.find(str)==st.end()){
                st.insert(str);
                solve(j+1,s);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
         solve(0,s);
         return ans;
    }
};
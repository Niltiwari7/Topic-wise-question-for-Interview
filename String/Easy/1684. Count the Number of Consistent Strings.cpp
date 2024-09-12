class Solution {
public:
    bool check(string &s,string &word){
        unordered_set<char>st(s.begin(),s.end());
        for(auto &it:word){
            if(st.find(it)==st.end()){
                return false;
            }
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        for(auto &w:words){
            if(check(allowed,w)){
                cnt++;
            }
        }
        return cnt;
    }
};
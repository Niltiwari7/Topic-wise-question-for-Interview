class Solution {
public:
    vector<vector<string>>result;
    bool isPlaindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(int i,string &s,vector<string>ds){
        if(i>=s.size()){
            result.push_back(ds);
            return;
        }

        for(int j = i;j<s.size();j++){
            if(isPlaindrome(s.substr(i,j-i+1))){
                ds.push_back(s.substr(i,j-i+1));
                solve(j+1,s,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        solve(0,s,ds);
        return result;
    }
};
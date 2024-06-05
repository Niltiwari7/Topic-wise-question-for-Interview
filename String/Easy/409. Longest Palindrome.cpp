class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int count = 0;
        for(int i= 0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp.erase(s[i]);
                count++;
            }else{
               mp[s[i]]++;
            }
        }
        if(mp.size()>0) return count*2+1;
        return count*2;
    }
};
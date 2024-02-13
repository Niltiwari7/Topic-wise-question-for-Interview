class Solution {
public:
    bool isPlaindrome(string &s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPlaindrome(words[i]))return words[i];
        }
        return "";
    }
};
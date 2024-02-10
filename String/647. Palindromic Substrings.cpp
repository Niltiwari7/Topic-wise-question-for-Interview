class Solution {
public:
    bool isPlaindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
       int count = 0;
       int n = s.size();
       for(int i=0;i<n;i++){
           for(int j = 1;j<=n-i;j++){
               string str = s.substr(i,j);
               if(isPlaindrome(str))count+=1;
           }
       } 
       return count;
    }
};
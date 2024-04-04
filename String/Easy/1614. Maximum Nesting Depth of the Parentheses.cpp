class Solution {
public:
    int maxDepth(string s) {
       int ans = 0;
       int lp=0;
   
       for(int i = 0;i<s.size();i++){
         if(s[i]=='(')lp++;
         if(s[i]==')')lp--;
         ans=max(lp,ans);
       } 
       return ans;
    }
};
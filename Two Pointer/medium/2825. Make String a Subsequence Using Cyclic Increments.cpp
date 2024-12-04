//Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i  = 0;
        int j = 0;
        int n = str1.size();
        while(i<n){
            if(str1[i]==str2[j]||(str1[i]+1)==str2[j]){
                i++;
                j++;
            }else if(str1[i]=='z' && str2[j]=='a'){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j==str2.size();
    }
};
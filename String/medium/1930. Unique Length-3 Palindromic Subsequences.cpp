class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char>letters(s.begin(),s.end());
        int res = 0;
        for(char l:letters){
            int left_idx = -1;
            int right_idx = -1;
            for(int i = 0;i<s.size();i++){
                if(s[i]==l){
                    if(left_idx==-1){
                        left_idx = i;
                    }
                    right_idx = i;
                }
            }
            unordered_set<char>st;
            for(int middle = left_idx+1;middle<=right_idx-1;middle++){
                st.insert(s[middle]);
            }
            res+=st.size();
        }
        return res;
    }
};
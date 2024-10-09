class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0){
            return 0;
        }
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};
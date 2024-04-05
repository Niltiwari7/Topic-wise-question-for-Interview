class Solution {
public:
    string makeGood(string s) {
       if(s.size()==0)return "";
       stack<char>st;
       for(int i = 0;i<s.size();i++){
        st.push(s[i]);
        while(!st.empty()  &&  (st.top()==s[i+1]-32 || st.top()==s[i+1]+32)){
            st.pop();  
            i+=1;
        }  
      } 
       string ans="";
       while(!st.empty()){
        ans+=st.top();
        st.pop();
       }
       reverse(begin(ans),end(ans));
       return ans;
    }
};
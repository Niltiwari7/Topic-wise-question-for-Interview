class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      sort(s.begin(),s.end());

      int cnt = 0;
      for(int i = s.size()-1;i>=0;i--){
          if(s[i]=='1'){
              cnt++;
          }
      }  
      cout<<cnt<<endl;
      string result = "";
      for(int i = 0;i<cnt-1;i++){
          result+="1";
      }
      cout<<result<<endl;
      for(int i = result.size();i<s.size()-1;i++){
          result+="0";
      }
      result+="1";
      return result;

    }
};
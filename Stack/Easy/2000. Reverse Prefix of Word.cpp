class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
       for( i = 0;i<word.size();i++){
        if(word[i]==ch){
            break;
        }
       }
      if(i==word.size()){
        return word;
      }
       int j = i;
        i = 0;
       while(i<=j){
        swap(word[i++],word[j--]);
       } 
       return word;
    }
};
//Iterative approach
class Solution {
public:
    int appendCharacters(string s, string t) {
       int i = 0;
       int  j = 0;
       while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
            cout<<i<<" "<<j<<endl;
        }else{
            i++;
        }
       } 
       return t.size()-j;
    }
};

//Recursive approach
class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        if (i == s.size()) {
            return t.size() - j;
        }
        if (s[i] == t[j]) {
            return solve(i + 1, j + 1, s, t);
        } else {
            return solve(i + 1, j, s, t);
        }
    }
    int appendCharacters(string s, string t) { return solve(0, 0, s, t); }
};
// using inbuilt swap method
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};

//using recursion
class Solution {
public:
    void solve(vector<char>&s,int i,int j){
        if(i>=j)return;
        swap(s[i],s[j]);
        solve(s,i+1,j-1);
    }
    void reverseString(vector<char>& s) {
       solve(s,0,s.size()-1);
    }
};
//using bitmainpulation
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                s[i] ^= s[j];
                s[j] ^= s[i];
                s[i] ^= s[j];
            }
            i++;
            j--;
        }
    }
};
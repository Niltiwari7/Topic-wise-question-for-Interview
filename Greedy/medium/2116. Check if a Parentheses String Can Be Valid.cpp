// Brute force
class Solution {
public:
    bool solve(int i, int open, int close, string &s, string &locked) {
    
        if (i == s.size()) {
            return open == close;
        }

        if (close > open) {
            return false;
        }

        if (locked[i] == '1') {
            if (s[i] == '(') {
                return solve(i + 1, open + 1, close, s, locked);
            } else { 
                return solve(i + 1, open, close + 1, s, locked);
            }
        } else {
            return solve(i + 1, open + 1, close, s, locked) || solve(i + 1, open, close + 1, s, locked);
        }
    }

    bool canBeValid(string s, string locked) {
        // If the length of the string is odd, it cannot be balanced
        if (s.size() % 2 == 1) {
            return false;
        }
        return solve(0, 0, 0, s, locked);
    }
};

// Optimized

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2==1){
            return false;
        }
        int balance = 0;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0'||s[i]=='(')balance++;
            else balance--;
            if(balance<0){
                return false;
            }
        }
        balance = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(locked[i]=='0'||s[i]==')')balance++;
            else balance--;
            if(balance<0){
                return false;
            }
        }
        return true;
    }
};
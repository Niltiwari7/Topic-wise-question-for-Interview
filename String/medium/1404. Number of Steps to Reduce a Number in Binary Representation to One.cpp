//brute force
class Solution {
public:
    void addOne(string &s){
        int i = s.length()-1;
        while(i>=0 && s[i]!='0'){
            s[i]='0';
            i--;
        }
        if(i<0){
            s='1'+s;
        }else{
            s[i]='1';
        }
    }
    int numSteps(string s) {
       int op=0;
       while(s.size()>1){
        int n = s.size()-1;
        if(s[n]=='0'){
            s.pop_back();
        }else{
            addOne(s);
        }
        op++;
       } 
       return op;
    }
};

//Optimised approach
class Solution {
public:
    int numSteps(string s) {
        int op = 0;
        int carry = 0;
        for(int i = s.size()-1;i>=1;i--){
            if(((s[i]-'0')+carry)%2==1){
                op+=2;
                carry=1;
            }else{
                op+=1;
            }
        }
        return op+carry;
    }
};
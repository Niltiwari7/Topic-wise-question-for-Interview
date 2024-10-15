class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        long long count = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                res+=count;
            }else{
                count++;
            }
        }
        return res;
    }
};
class Solution {
public:
    int passThePillow(int n, int time) {
        int count = 1;
        bool flag = true;
        for(int t = 0;t<time;t++){
            if(flag && count<=n){
                count++;
                if(count==n){
                    flag=false;
                }
            }else if(!flag && count>=1){
                count--;
                if(count==1){
                    flag = true;
                }
            }
        }
        return count;
    }
};
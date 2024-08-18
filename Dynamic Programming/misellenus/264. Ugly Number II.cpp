class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        arr[1] = 1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i = 2;i<=n;i++){
            int next2 = arr[i2]*2;
            int next3 = arr[i3]*3;
            int next5 = arr[i5]*5;

            int mini = min({next2,next3,next5});
            arr[i]  = mini;
            
            if(next2==mini){
                i2++;
            }

            if(next3==mini){
                i3++;
            }
            if(next5==mini){
                i5++;
            }
        }
        return arr[n];
    }
};
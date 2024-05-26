// bottom up
class Solution {
public:
    int dp[100001][2][3];
    int mod = 1e9+7;
    int solve(int n ,int Absent,int consecutiveLate){
         if(Absent>1){
            return 0;
        }

        if(consecutiveLate>2){
            return 0;
        }

        if(n==0){
            return 1;
        }   
        if(dp[n][Absent][consecutiveLate]!=-1){
            return dp[n][Absent][consecutiveLate];
        }

        int a = (solve(n-1,Absent+1,0))%mod;
        int b = (solve(n-1,Absent,consecutiveLate+1))%mod;
        int c = (solve(n-1,Absent,0))%mod;

        return dp[n][Absent][consecutiveLate] = ((a+b)%mod+c)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};

//top down

class Solution {
public:
     int mod = 1e9+7;
    int checkRecord(int n) {
        
        int dp[100001][2][3];

        for(int A = 0;A<=1;A++){
            for(int L=0;L<=2;L++){
                dp[0][A][L]=1;
            }
        }

        for(int day=1;day<=n;day++){
            for(int A=0;A<=1;A++){
                for(int L=0;L<=2;L++){
                    long result = dp[day-1][A][0];
                    result+=(L+1<=2)?dp[day-1][A][L+1]:0;
                    result+=(A+1<=1)? dp[day-1][A+1][0]:0;

                    dp[day][A][L]=result%mod;
                }
            }
        }
        return dp[n][0][0];
    }
};
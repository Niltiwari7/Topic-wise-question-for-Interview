//Brute force

class Solution {
public:
    
    int countStep(int ringIdx,int i,int n){
        int distance = abs(i-ringIdx);
        int wrapdistance = abs(n-distance);
        return min(distance,wrapdistance);
    }
    int solve(int ringIdx,int keyIdx,string &ring,string &key){
        if(keyIdx>=key.size())return 0;
        int result = INT_MAX;
        for(int i = 0;i<ring.size();i++){
            if(ring[i]==key[keyIdx]){
                int totalStep = solve(i,keyIdx+1,ring,key)+countStep(ringIdx,i,(int)ring.size())+1;
                result = min(result,totalStep);
            }
        }
        return result;
    }
    int findRotateSteps(string ring, string key) {
        
        return solve(0,0,ring,key);
    }
};

// Optimised approach - memoization

class Solution {
public:
    int dp[101][101];
    int countStep(int ringIdx,int i,int n){
        int distance = abs(i-ringIdx);
        int wrapdistance = abs(n-distance);
        return min(distance,wrapdistance);
    }
    int solve(int ringIdx,int keyIdx,string &ring,string &key){
        if(keyIdx>=key.size())return 0;
        if(dp[ringIdx][keyIdx]!=-1)return dp[ringIdx][keyIdx];
        int result = INT_MAX;
        for(int i = 0;i<ring.size();i++){
            if(ring[i]==key[keyIdx]){
                int totalStep = solve(i,keyIdx+1,ring,key)+countStep(ringIdx,i,(int)ring.size())+1;
                result = min(result,totalStep);
            }
        }
        return dp[ringIdx][keyIdx]= result;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,ring,key);
    }
};
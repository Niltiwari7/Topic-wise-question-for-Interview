class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto it:edges){
            int from = it[0];
            int to = it[1];
            indegree[to]++;
        }
        int chap = -1;
        int chapC = 0;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                if(chapC==1){
                    return -1;
                }
                chap = i;
                chapC++;
            }
        }
        return chapC==1?chap:-1;
    }
};
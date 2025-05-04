class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int count = 0;
    
            unordered_map<string,int>mp;
    
            for(int i = 0;i<dominoes.size();i++){
               string temp = to_string(min(dominoes[i][0],dominoes[i][1]))+"$"+to_string(max(dominoes[i][0],dominoes[i][1]));
    
                if(mp.count(temp)){
                   count+=mp[temp];
                }
                mp[temp]++;      
            }
            return count;
        }
    };
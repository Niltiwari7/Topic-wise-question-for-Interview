class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        vector<vector<int>>v;
        int i = 0;
        int j = skill.size()-1;
        long long pair_sum = skill[i]+skill[j];
        while(i<j){
            long long sum = skill[i]+skill[j];
            if(pair_sum==sum){
                v.push_back({skill[i],skill[j]});
            }
            i++;
            j--;
        }
        int n = skill.size();
        if(v.size()!=n/2)return -1;
        long long res=0;
        for(auto it:v){
            res+=(it[0]*it[1]);
        }
        return res;
    }
};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(auto &row:board){
            for(auto &ch:row){
                start+=to_string(ch);
            }
        }
        queue<string>q;
        q.push(start);
        string target="123450";
        unordered_map<int,vector<int>>mp;
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {2,4};
        unordered_set<string>vis;
        vis.insert(start);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                int idx = curr.find('0');
                for(int i:mp[idx]){
                    string newstate = curr;
                    swap(newstate[i],newstate[idx]);
                    if(vis.find(newstate)==vis.end()){
                        q.push(newstate);
                        vis.insert(newstate);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
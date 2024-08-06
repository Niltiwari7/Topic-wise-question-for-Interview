class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto &ch:word){
            mp[ch]++;
        }
        vector<int>freq;
        for(auto &it:mp){
            freq.push_back(it.second);
        }
        sort(begin(freq),end(freq),greater<int>());
        int key = 0;
        int totalPush = 0;
        for(auto it:freq){
            key++;
            if(key<9){
                totalPush+=it;
            }else if(key<17){
                totalPush+=it*2;
            }else if(key<25){
                totalPush+=it*3;
            }else{
                totalPush+=it*4;
            }
        }
        return totalPush;
    }
};
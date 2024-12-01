
//Time Complexity - O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        for(auto it:arr){
            if(it==0){
                if(mp[it]>=2){
                    return true;
                }
                continue;
            }
            if(mp.find(2*it)!=mp.end()){
                return true;
            }
        }
        return false;
    }
};
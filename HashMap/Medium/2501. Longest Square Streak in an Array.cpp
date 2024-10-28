class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        long long res = 0;
        unordered_map<long long,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:nums){
            long long ele = it;
            long long count = 1;
            long long square = ele*ele;
            while(mp.find(square)!=mp.end()){
                count++;
                square = square*square;
            }
            res = max(count,res);

        }
       return res<2?-1:res;
    }
};
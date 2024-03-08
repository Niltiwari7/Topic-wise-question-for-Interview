class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto ele:nums){
            mp[ele]++;
        }
        int maxFreq=0;
        for(auto it:mp){
            maxFreq=max(maxFreq,it.second);
        }
        int sum = 0;
        for(auto it:mp){
            if(it.second==maxFreq)sum+=it.second;
        }
        return sum;
    }
};
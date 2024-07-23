//using custom sorting
class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[1]==v2[1]){
            return v1[0]>v2[0];
        }
        return v1[1]<v2[1];
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        vector<vector<int>>vec;
        for(auto it:mp){
            vec.push_back({it.first,it.second});
        }

        sort(vec.begin(),vec.end(),comp);

        int i = 0;
        for(auto &it:vec){
            int freq = it[1];
            int ele = it[0];
            while(freq--){
                nums[i++]=ele;
            }
        }
        return nums;
    }
};

//using priority queue
class Solution {
public:

    bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.second){
            return a.first>b.second;
        }
        return a.second>b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums)mp[it]++;
        priority_queue<pair<int,int>>pq;


        for(auto it:mp){
            pq.push({-it.second,it.first});
        }

        int j = 0;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int temp =-i.first;
            while(temp--){
                nums[j++] = i.second;
            }
        }
        return nums;
    }
};
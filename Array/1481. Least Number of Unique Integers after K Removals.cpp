class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto ele:arr)mp[ele]++;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto ele:mp){
            pq.push(ele.second);
        }
        while(k>0){
            k-=pq.top();
            if(k>=0)pq.pop();
        }
        return pq.size();
    }
};
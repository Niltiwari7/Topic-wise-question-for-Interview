class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,
                      vector<pair<int,int>>,
                      greater<pair<int,int>>
                      >pq;
        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            auto [ele,idx] = pq.top();
            pq.pop();
            ele*=multiplier;
            nums[idx] = ele;
            pq.push({ele,idx});
        }
    return nums;
    }
};
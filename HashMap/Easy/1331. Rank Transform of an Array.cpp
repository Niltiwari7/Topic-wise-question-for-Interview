class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int count = 1;
        for (auto it : temp) {
            if (mp.find(it) == mp.end()) {
                mp[it] = count++;
            }
        }
        vector<int> result;
        for (auto it : arr) {
            result.push_back(mp[it]);
        }
        return result;
    }
};

/*
arr  = [37,12,28,9,100,56,80,5,12]
5,9,12,12,28,37,56, 80, 100
0 1 2 3  4    5  6  7    8
*/
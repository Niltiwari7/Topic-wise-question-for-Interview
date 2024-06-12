class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for (auto& it : arr1) {
            mp[it]++;
        }
        int j = 0;
        for (int i = 0; i < arr2.size(); i++) {
            while (mp[arr2[i]]>0) {
                arr1[j++] = arr2[i];
                mp[arr2[i]]--;
            }
        }

        for (auto it : mp) {
            while (it.second--) {
                arr1[j++] = it.first;
            }
        }
        return arr1;
    }
};
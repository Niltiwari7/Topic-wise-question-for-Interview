class Solution {
public:
    bool isExist(vector<int>& A, int ele, int j) {
        for (int k = 0; k <= j; k++) {
            if (A[k] == ele) {
                return true;
            }
        }
        return false;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {

            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (isExist(A, B[j], i)) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
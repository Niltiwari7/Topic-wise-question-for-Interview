class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            int m = 0; 
            for(int j = i + 1; j < n; j++) {
                m ^= arr[j - 1];
                int z = 0; 
                for(int k = j; k < n; k++) {
                    z ^= arr[k];
                    if (m == z) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

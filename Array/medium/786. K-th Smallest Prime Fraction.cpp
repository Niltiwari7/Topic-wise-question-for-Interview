class Solution {
public:
    struct data {
        float num;
        int val1;
        int val2;
    };

    static bool compare(const data& d1, const data& d2) {
        return d1.num < d2.num;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        vector<data> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                float ans = float(nums[i]) / nums[j];
                result.push_back({ans, nums[i], nums[j]});
            }
        }

        sort(result.begin(), result.end(), compare);

        return {result[k - 1].val1, result[k - 1].val2};
    }
};

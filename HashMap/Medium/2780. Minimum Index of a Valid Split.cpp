class Solution {
    public:
     bool isDominant(int cnt, int len) { return cnt * 2 > len; }
    
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> freq; 
            
            for (int num : nums) {
                freq[num]++;
            }
    
            int leftFreq = 0;
            unordered_map<int, int> leftCount;
            
            for (int i = 0; i < n - 1; i++) {
                leftCount[nums[i]]++;
                leftFreq = leftCount[nums[i]];
                int rightFreq = freq[nums[i]] - leftFreq;
    
                if (isDominant(leftFreq, i + 1) && isDominant(rightFreq, n - (i + 1))) {
                    return i;
                }
            }
    
            return -1;
        }
    };
    
    /*0 1 2 3 4
      1 , 2, 2 , 2
    
    
    */
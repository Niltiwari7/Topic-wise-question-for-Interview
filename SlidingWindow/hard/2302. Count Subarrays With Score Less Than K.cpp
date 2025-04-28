class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
          long long sum = 0;
          long long i = 0;
          long long j = 0;
          long long result = 0;
    
          while(j<size(nums)){
            sum+=nums[j];
            while(sum*(j-i+1)>=k){
                sum -= nums[i];
                i++;
            }
    
            result+=(j-i+1);
            j++;
          }  
          return result;
        }
    };
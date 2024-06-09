//Brute force

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = nums[i];
            for(int j = i+1;j<nums.size();j++){
                sum+=nums[j];
                cout<<"sum"<<sum<<endl;
                cout<<"len"<<j-i+1<<endl;
                if(sum%k==0 && ((j-i+1)>=2)){
                     cout<<sum<<endl;
                     cout<<"len "<<j-i+1<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};

//Optimal approach

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0]=-1;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            int remainder = sum%k;
            if(mp.find(remainder)!=mp.end()){
                if(i-mp[remainder]>=2){
                    return true;
                }
            }else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};
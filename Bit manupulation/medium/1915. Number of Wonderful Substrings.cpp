//brute force

class Solution {
public:
    bool check(string &s){
        if(s.size()==1)return true;
        unordered_map<char,int>mp;
        for(char &c:s){
            mp[c]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second%2==1){
                count++;
            }
        }
        return count<=1;
    }
    long long wonderfulSubstrings(string word) {
       long long ans = 0;
       for(int i = 0;i<word.size();i++){
        for(int j = 1;j<=word.size()-i;j++){
            string a = word.substr(i,j); 
            if(check(a)==true){   
                ans++;
            }
        }
       }
       return ans;
    }
};

// Optimize approach
class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1;
        int cum_xor = 0;

        ll result = 0;


        for(char &ch : word) {

            int shift = ch - 'a';

            cum_xor ^= (1 << shift);

            result += mp[cum_xor];

            for(char ch1 = 'a' ; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';

                ll check_xor = (cum_xor ^ (1 << shift));

                result += mp[check_xor];
            }

            mp[cum_xor]++;

        }

        return result;
    }
};
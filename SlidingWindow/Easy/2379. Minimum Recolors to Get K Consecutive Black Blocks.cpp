class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int i=0,j=0;
            int ans=INT_MAX;
            int cnt_w=0;
            int n=blocks.size();
            while(j<n){
                if(blocks[j]=='W')cnt_w++;
                if(j-i+1<k)j++;
                else if(j-i+1==k){
                    ans=min(ans,cnt_w);
                    if(blocks[i]=='W'){
                        cnt_w--;
                    }
                     i++;
                    j++;
                }
            }
            return ans;
        }
    };
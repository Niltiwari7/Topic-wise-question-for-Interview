class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1;i<=n;i++){
            int sumTox=(i*(i+1))/2;
           
            int sumXToN = n*(n+1)/2-((i-1)*(i))/2;
           
            if(sumTox==sumXToN)return i;
        }
        return -1;
    }
};
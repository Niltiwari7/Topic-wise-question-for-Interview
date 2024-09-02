class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(),chalk.end(),0L);
        int rem = k%sum;
        if(rem==0){
            return 0;
        }
        while(true){
            rem-=chalk[i%n];
            if(rem<0){
                return i%n;
            }
            i++;
        }
        return 0;
    }
};
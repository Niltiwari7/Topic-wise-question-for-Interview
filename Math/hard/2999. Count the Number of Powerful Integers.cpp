class Solution {
    public:
       long long solve(string &str,string &suffix,int limit){
        if(str.size()<suffix.size()){
            return 0;
        }
    
        long long count = 0;
        string trailString = str.substr(str.size() - suffix.size());
        
        int remainL = str.size() - suffix.size();
    
    
        for(int i = 0;i<remainL;i++){
            int digit = str[i] - '0';
    
            if(digit<=limit){
                count+=digit*pow(limit+1,remainL-i-1);
            }else{
                count+=pow(limit+1,remainL-i);
                return count;
            }
        }
        
        if(trailString>=suffix){
            count+=1;    
        }
        
        return count;
    
       }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string startstr = to_string(start-1);
            string finishstr = to_string(finish);
    
           return solve(finishstr, s, limit) - solve(startstr, s, limit);
    
        }
    };
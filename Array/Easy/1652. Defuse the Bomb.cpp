class Solution {
public:
  int get_next_K(vector<int>& code, int k, int idx) {
    int sum = 0;
    int n = code.size();
    idx = (idx + 1) % n;
    while (k > 0) {
        sum += code[idx]; 
        idx = (idx + 1) % n; 
        k--;
    }
    return sum;
}
int get_prev_K(vector<int>& code, int k, int i) {
    int sum = 0;
    int n = code.size();
    k = abs(k);
    i = (i - 1 + n) % n; 
    while (k > 0) {
        sum += code[i];          
        i = (i - 1 + n) % n;     
        k--;
    }
    return sum;
}

 vector<int> decrypt(vector<int>& code, int k) {
      vector<int>ans;
      for(int i = 0;i<code.size();i++){
          if(k==0){
            ans.push_back(0);
          }else if(k>0){
            ans.push_back(get_next_K(code,k,i));
          }else{
            ans.push_back(get_prev_K(code,k,i));
          }
      }
      return ans;
    }
};
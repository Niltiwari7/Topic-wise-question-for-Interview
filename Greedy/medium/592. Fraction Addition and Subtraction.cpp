class Solution {
public:
    bool isnum(char ch) {
        return ch >= '0' && ch <= '9';
    }

    string fractionAddition(string expression) {
        vector<int> deno;
        vector<int> num;
        expression = "+" + expression; 
        
        for(int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-') {
                string ans = "";
                ans += expression[i]; 
                i++;  
                while (i < expression.size() && isnum(expression[i])) {
                    ans += expression[i];
                    i++;
                }

                if (ans.size() > 1) {  
                    num.push_back(stoi(ans));  
                } 

                i--;  
            } 
            else if (expression[i] == '/') {
                i++;  
                string ans = "";
                while (i < expression.size() && isnum(expression[i])) {
                    ans += expression[i];
                    i++;
                }

                if (!ans.empty()) {
                    deno.push_back(stoi(ans)); 
                } 
                i--;  
            }
        }
        int lcm = deno[0];
        for(int i = 1;i<deno.size();i++){
          lcm = (lcm*deno[i])/(__gcd(lcm,deno[i]));
        }
        
        int sum = 0;
        for(int i = 0;i<num.size();i++){
            sum+=((lcm/deno[i])*num[i]);
        }
        
        int res = __gcd(abs(sum),abs(lcm));
        int num1 = sum/res;
        int num2 = lcm/res;
        string result = to_string(num1)+"/"+to_string(num2);

        return result;
    }
};

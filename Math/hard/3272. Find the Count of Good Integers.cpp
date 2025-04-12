class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> st;
            vector<long long> factorial(11, 1);
    
           
            for (int i = 1; i < 11; i++) {
                factorial[i] = factorial[i - 1] * i;
            }
          
            int d = (n + 1) / 2;
            int start = pow(10, d - 1);
            int end = pow(10, d) - 1;
            long long result = 0;
    
            for (int num = start; num <= end; num++) {
                string leftHalf = to_string(num);
                string full = "";
    
                if (n % 2 == 0) {
                    string rightHalf = leftHalf;
                    reverse(rightHalf.begin(), rightHalf.end());
                    full = leftHalf + rightHalf;
                } else {
                    string rightHalf = leftHalf.substr(0, d - 1);
                    reverse(rightHalf.begin(), rightHalf.end());
                    full = leftHalf + rightHalf;
                }
    
                long long number = stoll(full);
                if (number % k != 0) continue;
    
                sort(full.begin(), full.end());
                st.insert(full);
            }
    
            
           for (const string &s : st) {
    
                vector<int> count(10, 0);
                for (char ch : s) {
                    count[ch - '0']++;
                }
    
                int totalDigits = s.size();
                long long totalPerm = factorial[totalDigits];
    
                for (int i = 0; i < 10; i++) {
                    totalPerm /= factorial[count[i]];
                }
    
             
                if (count[0] > 0) {
                    count[0]--;
                    long long zeroStartPerm = factorial[totalDigits - 1];
                    for (int i = 0; i < 10; i++) {
                        zeroStartPerm /= factorial[count[i]];
                    }
                    totalPerm -= zeroStartPerm;
                    count[0]++;
                }
    
                result += totalPerm;
            }
    
            return result;
        }
    };
    
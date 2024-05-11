// brute force
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;
        for(int manager = 0;manager<n;manager++){
          double managerRatio = (double)wage[manager]/quality[manager]; 
          vector<double>group;
          for(int worker = 0;worker<n;worker++){
            double worker_wage = quality[worker]*managerRatio;
            if(worker_wage>=wage[worker]){
                group.push_back(worker_wage);
            }
          }
          if(group.size()<k){
            continue;
          }
          priority_queue<double,vector<double>>pq;
          double sum_wage=0;
          for(double &wage:group){
            sum_wage+=wage;
            pq.push(wage);
            if(pq.size()>k){
                sum_wage-=pq.top();
                pq.pop();
            }
          }
          result = min(result,sum_wage);
        }
        return result;
    }
};

//optimal solution
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
    }

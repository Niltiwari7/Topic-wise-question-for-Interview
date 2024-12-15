class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>>pq;
        for (int i = 0; i < n; i++) {
            double curr_PR = (double)classes[i][0] / classes[i][1];
            double nxt_PR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = nxt_PR - curr_PR; 
            pq.push({delta,i});   
        }
        while (extraStudents--) {
            auto [curr,idx] = pq.top();
            pq.pop();
            classes[idx][0]+=1;
            classes[idx][1]+=1;
            double curr_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double delta = new_PR - curr_PR;
            pq.push({delta,idx});
        }
        double res = 0.0;
        for(int i = 0;i<n;i++){
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};
class Solution {
public:
   int timeToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
         sort(timePoints.begin(), timePoints.end());
        
        int minDifference = INT_MAX;
        int n = timePoints.size();
    
        int firstTime = timeToMinutes(timePoints[0]);
        int previousTime = firstTime;
    
        for (int i = 1; i < n; ++i) {
            int currentTime = timeToMinutes(timePoints[i]);
            minDifference = min(minDifference, currentTime - previousTime);
            previousTime = currentTime;
        }
        
        int lastTime = timeToMinutes(timePoints[n - 1]);
        minDifference = min(minDifference, (firstTime + 1440) - lastTime);
        
        return minDifference;
        return 0;
    }
};

/*
[23:59 00:00]
i = 0   firsttime = 23*60+59 = 1439 prevTime = 1439 minD = INT_MAX
i=1     firsttime = 1439        prevTime = 1439 currTime = 60*0+0 = 0 minDiff = 1439

n = 
*/
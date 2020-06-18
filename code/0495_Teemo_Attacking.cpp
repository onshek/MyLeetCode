class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (timeSeries.empty()) return res;
        for (int i=0; i<timeSeries.size()-1; i++) {
            if (timeSeries[i] + duration <= timeSeries[i+1]) {
                res += duration;
            } else {
                res += timeSeries[i+1] - timeSeries[i];
            }
        }
        return res + duration;
    }
};
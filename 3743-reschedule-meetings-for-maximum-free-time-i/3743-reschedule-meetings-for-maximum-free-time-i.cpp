class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int sum = 0;
        int ans = INT_MIN;
        vector<int> gap(n + 1);
        for (int i = 1; i < n; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1]; 
        int i = 0, j = k;
        for (int w = i; w <= n && w <= j; w++) {
            sum += gap[w];
        }
        ans = max(ans, sum);
        while (j < n) {
            sum -= gap[i++];
            sum += gap[++j];
            ans = max(ans, sum);
        }

        return ans;
    }
};
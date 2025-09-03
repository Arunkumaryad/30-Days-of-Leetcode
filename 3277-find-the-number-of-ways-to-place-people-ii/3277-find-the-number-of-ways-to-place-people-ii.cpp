class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int cnt = 0;
        for(int i=0;i<n;i++) {
            int maxi = INT_MIN;
            for(int j=i+1;j<n;j++) {
                if(points[j][1] > points[i][1]) continue;
                if(points[j][1] > maxi) {
                    cnt++;
                    maxi = points[j][1];
                }
            }
        }
        return cnt;
    }
};
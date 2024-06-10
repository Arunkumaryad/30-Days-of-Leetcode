class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ans(heights);
        sort(ans.begin(),ans.end());
        int cnt = 0;
        int n = heights.size();
        for(int i=0;i<n;i++) {
            if(heights[i] != ans[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
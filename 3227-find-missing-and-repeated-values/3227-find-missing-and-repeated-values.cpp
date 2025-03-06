class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n*m;
        int repeating = -1;
        int missing = -1;
        vector<int>ans(total+1,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[grid[i][j]]++;
            }
        }
        for(int i=1;i<=total;i++) {
            if(ans[i] == 2) repeating = i;
            if(ans[i] == 0) missing = i;
        }
        return {repeating,missing};
    }
};
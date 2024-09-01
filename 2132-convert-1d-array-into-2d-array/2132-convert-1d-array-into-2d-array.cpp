class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        if( s != m*n) {
            return {};
        }
        int cnt = 0;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans[i][j] = original[cnt];
                cnt++;
            }
        }
        return ans;
    }
};
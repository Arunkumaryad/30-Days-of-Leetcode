class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=m-1;j>=0;j--) {
                if(mat[i][j] == 1) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                ans[i][j] = cnt;
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int k = INT_MAX;
                for(int m=i;m<n;m++) {
                    k = min(k,ans[m][j]);
                    res += k;
                }
            }
        }
        return res;
    }
};
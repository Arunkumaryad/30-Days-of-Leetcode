class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        int oneCnt = INT_MIN;
        int rowNo = -1;
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 1) {
                    sum++;
                }
            }
            if(sum > oneCnt) {
                oneCnt = sum;
                rowNo = i;
            }
        }
        ans.push_back(rowNo);
        ans.push_back(oneCnt);
        return ans;
    }
};
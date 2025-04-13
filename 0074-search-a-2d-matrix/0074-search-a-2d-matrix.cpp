class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int start = 0;
        int end = total - 1;
        int mid = start + (end-start) / 2;
        while(start <= end) {
            int rowIndx = mid / col;
            int colIndx = mid % col;
            int currNumber = matrix[rowIndx][colIndx];
            if(currNumber == target) {
                return true;
            }
            if(currNumber < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return false;
    }
};
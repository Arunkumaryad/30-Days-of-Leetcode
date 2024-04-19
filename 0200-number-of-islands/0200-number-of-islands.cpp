class Solution {
public:
    int dfs (vector<vector<char>>& grid, int i, int j) {
        //base case
        if(i < 0 || j < 0 || i>= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'x') {
            return 0;
        }
        //visited
        grid[i][j] = 'x';
        int marked = 1;
        int bakiKaAns = dfs(grid,i-1,j) | dfs(grid,i,j-1) | dfs(grid,i+1,j) | dfs(grid,i,j+1);
        return marked | bakiKaAns;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans += dfs(grid,i,j);
            }
        }
        return ans;
    }
};
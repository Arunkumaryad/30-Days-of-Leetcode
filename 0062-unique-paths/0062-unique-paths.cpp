class Solution {
public:
    int uniquePaths(int m, int n) {
        int p = m+n-2;
        int a = min(m,n)-1;
        double ans = 1;
        for(int i=1;i<=a;i++,p--) {
            ans = ans*p/i;
        }
        return (int) ans;
    }
};
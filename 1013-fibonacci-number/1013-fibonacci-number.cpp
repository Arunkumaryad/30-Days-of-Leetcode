class Solution {
public:
    int solveUsingRec(int n) {
        //base case
        if(n == 0 || n == 1) {
            return n;
        }
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }
    int fib(int n) {
        int ans = solveUsingRec(n);
        return ans;
    }
};
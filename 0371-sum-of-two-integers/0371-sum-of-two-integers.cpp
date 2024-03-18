class Solution {
public:
    int getSum(int a, int b) {
        int ans = a;
        while(b) {
            ans = a ^ b;
            b = (a & b) << 1;
            a = ans;
        }
        return ans;
    }
};
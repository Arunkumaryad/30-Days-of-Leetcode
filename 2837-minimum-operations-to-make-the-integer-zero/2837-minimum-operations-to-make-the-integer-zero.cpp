class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++) {
            long long sum = (long long)num1 - (long long)i * num2;
            if(sum < 0) {
                continue;
            }
            if(sum < i) {
                continue;
            }
            int ones = __builtin_popcountll(sum);
            if(ones <= i) {
                return i;
            }
        }
        return -1;
    }
};
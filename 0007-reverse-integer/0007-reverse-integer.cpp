class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        int temp = x;
        while(temp != 0) {
            int digit = temp % 10;
            rev = rev*10 + digit;
            temp /= 10;
        }
        if(rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }
        return (int) rev;
    }
};
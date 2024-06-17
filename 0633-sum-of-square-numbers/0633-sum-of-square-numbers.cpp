class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0) {
            return true;
        }
        long int start = 0;
        long int end = sqrt(c);
        while(start <= end) {
            long int curr = start*start + end*end;
            if(curr == c) {
                return true;
            }
            else if(curr < c) {
                start++;
            }
            else {
                end--;
            }
        }
        return false;
    }
};
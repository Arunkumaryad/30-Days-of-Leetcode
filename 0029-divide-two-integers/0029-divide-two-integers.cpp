class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        long long  s=0;
        long long e=abs(dividend);
        long long ans=-1;
        long long mid=s+(e-s)/2;
        while(s<=e)
        {
            if(abs(mid*divisor) == abs(dividend))
            {
                ans=mid;
                break;
            }
            else if(abs(mid*divisor) > abs(dividend))
            {
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)){
            return ans;
        }
        else{
            return -ans;
        }
    }
};
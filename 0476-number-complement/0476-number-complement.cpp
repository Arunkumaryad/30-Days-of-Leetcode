class Solution {
public:
    int findComplement(int num) {
        int msb=(int)(log2(num));
        if(num==0)
        {
            return 1;
        }
        int sum=0;
        for(int i=msb;i>=0;i--)
        {
            if(num&(1<<i))
            {
                continue;
            }
            else
            {
                sum=sum+pow(2,i);
            }
        }
        return sum;
        
    }
};
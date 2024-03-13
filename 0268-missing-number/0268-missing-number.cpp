class Solution {
public:
    int xorr(vector<int>& nums)
    {
        int n=nums.size();
        int ans=0;
        //xor array elemnt.
        for(int i=0;i<n;i++)
        {
            ans^=nums[i];
        }
        //step-2.xor range
        for(int i=0;i<=n;i++)
        {
            ans^=i;
        }
        return ans;
    }
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i==nums[i])
        //         continue;
        //     else
        //       return i;
        // }
        // return nums.size();

        return xorr(nums);
    }
};
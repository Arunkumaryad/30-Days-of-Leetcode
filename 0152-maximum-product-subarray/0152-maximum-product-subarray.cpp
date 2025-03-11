class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int prod = 1;
        //from left to right
        for(int i=0;i<n;i++) {
            prod *= nums[i];
            ans = max(ans,prod);
            if(prod == 0) prod = 1;
        }
        prod = 1;
        //from right to left
        for(int i = n-1;i>=0;i--) {
            prod *= nums[i];
            ans = max(ans,prod);
            if(prod == 0) prod = 1;
        }
        return ans;
    }
};
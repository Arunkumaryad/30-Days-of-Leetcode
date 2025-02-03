class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incCnt = 1;
        int decCnt = 1;
        int n = nums.size();
        int ans = 1;
        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                incCnt++;
                decCnt = 1;
            }
            else if(nums[i] < nums[i-1]) {
                decCnt++;
                incCnt = 1;
            }
            else {
                incCnt = 1;
                decCnt = 1;
            }
            int maxi = max(incCnt,decCnt);
            ans = max(ans,maxi);
        }
        return ans;
    }
};
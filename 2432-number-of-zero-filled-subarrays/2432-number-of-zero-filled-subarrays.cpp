class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long int cnt = 0;
        long long int streak = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                streak++;
                cnt += streak;
            }
            else {
                streak = 0;
            }
        }
        return cnt;
    }
};
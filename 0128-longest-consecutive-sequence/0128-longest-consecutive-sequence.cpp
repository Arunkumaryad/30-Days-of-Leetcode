class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int smallest = INT_MIN;
        int cnt = 0;
        int maxi = 1;
        for(int i=0;i<n;i++) {
            if(nums[i]-1 == smallest) {
                cnt++;
                smallest = nums[i];
            }
            else if(nums[i] != smallest) {
                cnt = 1;
                smallest = nums[i];
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
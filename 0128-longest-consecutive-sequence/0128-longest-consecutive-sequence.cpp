class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        //special or base case
        if(n == 0) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mini = INT_MIN;
        int cnt = 0;
        int maxi = 1;
        for(int i=0;i<n;i++) {
            if(nums[i]-1 == mini) {
                cnt++;
                mini = nums[i];
            }
            else if(nums[i] != mini) {
                cnt = 1;
                mini = nums[i];
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
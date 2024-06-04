class Solution {
public:
    int findMin(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[0];

        int n = nums.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++) {
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int mini = nums[0];
        for(int i=1;i<n;i++) {
            if(nums[i]-mini > k) {
                cnt++;
                mini = nums[i];
            }
        }
        return cnt;
    }
};
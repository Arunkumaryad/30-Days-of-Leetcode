class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //using linear search.
        // int n = nums.size();
        // int ans = 0;
        // for(int i=0;i<n;i++) {
        //     if(nums[i] == target) {
        //          ans = i;
        //     }
        //     if(nums[i] + 1 <= target) {
        //         ans = i+1;
        //     }
        // }
        // return ans;


        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end - start) / 2;
        while(start <= end) {
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid -1;
            }
            mid = start + (end - start) / 2;
        }
        return start;
    }
};
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        int mid = start + (end - start) / 2;
        while(start <= end) {
            if(nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
    int lastOccurrence(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        int mid = start + (end - start) / 2;
        while(start <= end) {
            if(nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<int,int>p;
        p.first = firstOccurrence(nums,target);
        p.second = lastOccurrence(nums,target);
        return {p.first, p.second};
    }
};
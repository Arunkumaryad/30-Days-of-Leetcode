class Solution {
public:
    int firstOccurance(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int start = 0;
        int end = n-1;
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

    int lastOccurance(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int start = 0;
        int end = n-1;
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
        p.first = firstOccurance(nums,target);
        p.second = lastOccurance(nums,target);
        return {p.first,p.second};
    }
};
class Solution {
public:
    int firstOccurence(vector<int>& nums, int n,  int target) {
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(nums[mid] == target) {
                ans = mid;
                end = mid-1;
            }
            else if(nums[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums, int n, int target) {
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        int ans = -1;
        while(start <= end) {
            if(nums[mid] == target) {
                ans = mid;
                start = mid+1;
            }
            else if(nums[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        pair<int,int>p;
        p.first = firstOccurence(nums,n,target);
        p.second = lastOccurence(nums,n,target);
        return {p.first,p.second};
    }
};
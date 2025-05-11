class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n  = arr.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end - start) / 2;
        while(start <= end) {
            int ele = arr[mid] - (mid+1);
            if(ele < k) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return k + end + 1;
    }
};
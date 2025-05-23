class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(auto num : nums1) {
            ans.push_back(num);
        }
        for(auto num : nums2) {
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        int n = ans.size();
        return n%2 ? ans[n/2] : (ans[n/2-1] + ans[n/2]) / 2.0;
    }
};
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(auto n1 : nums1) {
            mp[n1[0]] += n1[1];
        }
        for(auto n2 : nums2) {
            mp[n2[0]] += n2[1];
        }
        for(auto it : mp) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};
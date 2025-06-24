class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndex;
        for(int i=0;i<n;i++) {
            if(nums[i] == key) {
                keyIndex.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            for(auto j : keyIndex) {
                if(abs(i-j) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
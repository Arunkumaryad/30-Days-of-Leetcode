class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        for(auto i : nums) {
            for(auto j : nums) {
                if(i == -j) {
                    maxi = max(maxi,j);
                }
            }
        }
        return maxi;
    }
};
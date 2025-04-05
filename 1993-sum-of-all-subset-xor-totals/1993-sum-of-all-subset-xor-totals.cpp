class Solution {
private:
    int rec(int i, int xorVal, int n, vector<int>& nums) {
        if (i == n) return xorVal;
        if (i > n) return 0;

        int pick = rec(i + 1, xorVal ^ nums[i], n, nums);
        int dont = rec(i + 1, xorVal, n, nums);
        return pick + dont;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return rec(0, 0, n, nums);
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int ans = 0;
        while(start < end) {
            int diff = min(height[start],height[end]) * (end-start);
            ans = max(ans,diff);
            if(height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }
        return ans;
    }
};
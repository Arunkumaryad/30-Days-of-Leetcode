class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxi = 0;
        for(int i=0;i<n;i++) {
            minPrice = min(minPrice, prices[i]);
            int diff = prices[i]-minPrice;
            maxi = max(maxi,diff);
        }
        return maxi;
    }
};
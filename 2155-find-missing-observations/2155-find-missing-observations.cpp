class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int total = size + n;
        int total_sum = mean*total;
        int sum = 0;

        for (int i = 0; i < size; i++){
            sum += rolls[i];
        }

        int remaining = total_sum-sum;

        if (remaining > n*6 || remaining < n){
            return {};
        }
        vector<int> ans(n, remaining/n);
        int remainder = remaining%n;

        for (int i = 0; i < remainder; i++){
            ans[i]++;
        }
        if(remaining!=0 && n==0 || n!=0 && remaining==0)
        {
            return {};
        }
        return ans;
    }
};
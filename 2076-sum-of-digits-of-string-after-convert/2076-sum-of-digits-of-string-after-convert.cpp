class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        for(char ch : s) {
            ans += to_string(ch - 'a' + 1);
        }
        while(k > 0) {
            int temp = 0;
            for(char ch : ans) {
                temp += ch - '0';
            }
            ans = to_string(temp);
            k--;
        }
        return stoi(ans);
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int n = str.size();
        int start = 0;
        int end = n-1;
        while(start <= end) {
            if(str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
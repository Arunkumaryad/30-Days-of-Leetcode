class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string temp, ans;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                temp += s[i]; 
            } else if (!temp.empty()) {
                st.push(temp); 
                temp = ""; 
            }
        }
        if (!temp.empty()) {
            st.push(temp);
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }

        return ans;
    }
};

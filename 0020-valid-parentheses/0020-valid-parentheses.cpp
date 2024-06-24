class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                //open bracket.
                st.push(ch);
            }
            else{
                if(!st.empty()) {
                    if(ch == ')' && st.top() == '(') {
                        st.pop();
                    }
                    else if(ch == '}' && st.top() == '{') {
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '[') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
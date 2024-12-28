class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s.find(part) != string::npos) {
                //part found in the string
                s.erase(s.find(part),part.length());
            }
        }
        return s;
    }
};
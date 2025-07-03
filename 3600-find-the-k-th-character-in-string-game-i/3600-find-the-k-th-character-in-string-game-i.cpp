class Solution {
public:
    char kthCharacter(int k) {
        string org="a";
        while(org.length()<=k)
        {
            string neww="";
            for(char c:org)
            {
                neww+=++c;
            }
            org+=neww;
        }
        return org[k-1];
    }
};
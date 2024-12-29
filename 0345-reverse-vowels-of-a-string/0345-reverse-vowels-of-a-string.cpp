class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            if(isVowel(s[start]) && isVowel(s[end]))
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(isVowel(s[start])==0)
            {
                start++;
            }
            else{
                end--;
            }
        }
        return s;
    }
};
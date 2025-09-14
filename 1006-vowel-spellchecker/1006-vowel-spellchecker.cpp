class Solution {
public:
    bool cons(char c)
    {
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
            return true;
        return false;
    }
    string modify(string s)
    {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ans+="$";
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        int n = wordlist.size();
        
        map<string,int> mp_exact;
        map<string,int> mp_lower;
        map<string,int> mp_modified;
        vector<string> lower(n);
        for(int i=0;i<n;i++)
        {
            string s = wordlist[i];
            mp_exact[s]=i+1;
            transform(s.begin(),s.end(),s.begin(),::tolower);
            lower[i]=s;
            if(!mp_lower[s]){
                mp_lower[s]=i+1;
            }
            
            string modified = modify(s);
            if(!mp_modified[modified]){
                mp_modified[modified]=i+1;
            }
        
        }

        int m = queries.size();
        vector<string> ans;
        for(int i=0;i<m;i++)
        {
            string q = queries[i];
            if(mp_exact[q]){
                ans.push_back(q); 
            }else{
                transform(q.begin(),q.end(),q.begin(),::tolower);
                if(mp_lower[q])
                {
                    int ind = mp_lower[q]-1;
                    ans.push_back(wordlist[ind]);
                }else{  
                    string q_mod = modify(q);
                    if(mp_modified[q_mod])
                    {
                        int ind = mp_modified[q_mod]-1;
                        ans.push_back(wordlist[ind]);
                    }else{
                        ans.push_back("");
                    }
                }
            }
        }
        return ans; 
    }
};
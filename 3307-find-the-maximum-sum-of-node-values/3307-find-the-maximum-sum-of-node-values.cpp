class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<pair<int,int>>forms;

        priority_queue<pair<int,int>>positiveEffect;
        priority_queue<pair<int,int>>negEffect;

        long long ans=0;
        int ind=0;
        for(auto &num:nums){
            int updatedForm=num^k;
            forms.push_back({num,updatedForm});
            ans+=num;
            if(updatedForm-num>0){positiveEffect.push({updatedForm-num,ind});}
            else {negEffect.push({updatedForm-num,ind});}
            ind++;
        }

        while(!positiveEffect.empty()){
            if(positiveEffect.size()<2) break;
            auto t1=positiveEffect.top();positiveEffect.pop();
            auto t2=positiveEffect.top();positiveEffect.pop();
            ans+=(t1.first+t2.first);
        }

        if(positiveEffect.empty() || negEffect.empty()) return ans;
        int neg=negEffect.top().first;
        int pos=positiveEffect.top().first;
        (pos+neg>0) ? ans+=pos+neg : ans=ans;
        return ans;

    }
};
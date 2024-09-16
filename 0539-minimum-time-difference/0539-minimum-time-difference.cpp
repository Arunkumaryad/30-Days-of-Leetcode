class Solution {
public:
    int convertToMin(string& str) {
        int hr = stoi(str.substr(0,2));
        int min = stoi(str.substr(3,2));
        int ans = hr*60+min;
        return ans;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;
        for(auto it : timePoints) {
            mins.push_back(convertToMin(it));
        }
        //sort 
        sort(mins.begin(),mins.end());
        int ans = INT_MAX;
        for(int i=0;i<mins.size()-1;i++) {
            ans = min(ans,mins[i+1]-mins[i]);
        }
        int lastDiff = mins[0] + 1440 - mins[mins.size()-1];
        ans = min(ans,lastDiff);
        return ans;
    }
};
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void mark(int day){
        parent[day]=day+1;
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<pair<int,int>> v;
        int maxi=0;
        for(int i=0;i<events.size();i++){
            v.push_back({events[i][1],events[i][0]});
            maxi=max(maxi,events[i][1]);
        }
        sort(v.begin(),v.end());
        int cnt=0;
        DisjointSet ds(maxi+2);
        for(int i=0;i<v.size();i++){
           int s=v[i].second;
           int e=v[i].first;
           int av=ds.findUPar(s);
           if(av<=e){
            cnt++;
            ds.mark(av);
           }
        }
        return cnt;
    }
};
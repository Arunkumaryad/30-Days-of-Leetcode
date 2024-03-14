class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0;
        int b=0;
        vector<int>ans;
        for(int i=0;i<m+n;i++)
        {
            if(a<m && b<n && nums1[a]<=nums2[b])
            {
                ans.push_back(nums1[a]);
                a++;
            }
            else if(a>=m)
            {
                ans.push_back(nums2[b]);
                b++;
            }
            else if(a<m && b<n && nums1[a]>=nums2[b])
            {
                ans.push_back(nums2[b]);
                b++;
            }
            else if(b>=n)
            {
                ans.push_back(nums1[a]);
                a++;
            }
        }
         for(int i=0;i<n+m;i++)
        {
            nums1[i]=ans[i];
        }
    }
};
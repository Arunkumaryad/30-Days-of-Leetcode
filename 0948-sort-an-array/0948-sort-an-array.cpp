class Solution {
public:
    void merge(vector<int>& nums,int start,int end){
        int N=end-start+1;
        int gap=(N/2) + (N%2);
        while(gap>0)
        {
            int i=start;
            int j=start+gap;
            while(j<=end)
            {
                if(nums[i]>nums[j])
                {
                    swap(nums[i],nums[j]);
                }
                i++;
                j++;
            }
            gap=gap<=1 ? 0 : (gap/2) + (gap%2);
        }
    }
    void mergeSort(vector<int>& nums,int start,int end)
    {
        if(start>=end) 
           return;
        int mid=start+(end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        mergeSort(nums,start,end);
        return nums;
    }
};
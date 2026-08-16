class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k)
        return -1;
        double windowsum=0;
        double windowavg=0;
        for (int i=0;i<k;i++){
            windowsum+=nums[i];
            windowavg=windowsum/k;
        }
        double maxavg=windowavg;
        for(int i=k;i<n;i++)
        {
            windowsum+=nums[i]-nums[i-k];
            windowavg=windowsum/k;
            maxavg=max(maxavg,windowavg);
        }
        return maxavg;
    }
};
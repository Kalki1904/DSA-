class Solution {
public:
    bool sum(vector<int>& nums,int n,int threshold){
        int s=0;
        for(auto num:nums){
            s+=(num+n-1)/n;
        }
        return s<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        int result=-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(sum(nums,mid,threshold)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};

class Solution {
public:
    bool possible(vector<int>& nums,int mid,int k){
        k--;
        int place=nums[0];
        for(int stall:nums){
            if(stall-place>=mid){
                place=stall;
                k--;
                if(k==0)return true;
            }
        }
        return k==0;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1]-nums[0];
        int result=-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(possible(nums,mid,k)){
                result=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
};

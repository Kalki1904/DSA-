class Solution {
public:
    bool possible(vector<int>& weights,int capacity,int days){
        int total=0;
        int day=1;
        for(int weight:weights){
            if(weight+total<=capacity)total+=weight;
            else{
                day++;
                total=weight;
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        int result=-1;
        for(int weight:weights)high+=weight;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,mid,days)){
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

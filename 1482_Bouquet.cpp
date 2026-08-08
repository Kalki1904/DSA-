class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int k,int m){
        int count =0;
        int bloomed=0;
        for(int i=0;i<bloomDay.size();i++){
            if(day>=bloomDay[i])count++;
            else{
                bloomed+=count/k;
                count=0;
            }       
        }
        bloomed+=count/k;
        return bloomed >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL*k*m;
        if(total>bloomDay.size())return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high =*max_element(bloomDay.begin(),bloomDay.end());
        int days=-1;
        while(low<=high){
            int mid=low +(high-low)/2;
            if(possible(bloomDay,mid,k,m)){
                days=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return days;
    }
};

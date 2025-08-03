#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>a,int n,int m,int mid){
    int painter_count=1;
    int time=0;
    for(int i=0;i<n;i++){
        if(time+a[i] <= mid){
            time+=a[i];
        }
        else if(painter_count++ > m || a[i] > mid){
            return false;
        }
        else{
            painter_count++;
            time=a[i];
        }
    }
    return true;
}

int painter_partition(vector<int>a,int n,int m){
    int s=0;
    int e=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        e+=a[i];
    }
    int mid=s+(e-s)/2;
    while(s<=e){
        if (isPossible(a,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cout <<"Enter Total number of boards" << endl;
    cin >>n;
    int m;
    cout << "Enter total number of workers" << endl;
    cin >>m;
    vector<int>a(n);
    cout << "Enter the section of board" << endl;
    for(int &i:a){
        cin >>i;
    }
    cout << "Minimum time = " << painter_partition(a,4,2);
}
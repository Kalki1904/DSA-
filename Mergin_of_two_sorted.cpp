#include<bits/stdc++.h>
using namespace std;
vector<int> merging(vector<int>& arr1,vector<int>arr2){
    int n =arr1.size();
    int m=arr2.size();
    int i=0;int j=0 ;
    while(i!=n && j!=m){
        
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            
            arr1.insert(arr1.begin()+i,arr2[j]);
            j++;
            i++;
        }
        else{
            arr1.insert(arr1.begin()+i,arr1[i]);
            i++;
            j++;
        }
    }
    while(i==n && j!=m){
        arr1.push_back(arr2[j]);
        j++;
    }
    
return arr1;

}

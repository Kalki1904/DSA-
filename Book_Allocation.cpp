#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>a,int mid,int n,int m){
    int Student_count=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]<=mid){
            sum+=a[i];
        }
        else if(Student_count++>m || a[i] > mid){
            return false;
        }
        else{
            Student_count++;
            sum=a[i];
        }
    }
    return true;

}

int book_allocation(vector<int>a,int n,int m){
    int s=0;
    int e=0;
    int ans=0;
    for(int i=0;i<n;i++){
        e+=a[i];
    }
    int mid =s+(e-s)/2;

    while(s<=e){
        if (isPossible(a,mid,n,m)){
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
    int n=0; // Total Number of Books
    int m=0; // Total Number of students
    vector<int>a(n);
    for(int &i:a){
        cin >> i;
    }
    
    cout << "Answer is = " << book_allocation(a,n,m);


}

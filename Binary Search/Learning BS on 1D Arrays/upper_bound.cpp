#include<bits/stdc++.h>
using namespace std;
// Simple Use a res variable
// For lower bound if we go right store it and then go right because the and is there we are searching for max value that is smaller than and equal to x
// for upper bound if we go left store it and then go left because the ans is there we are searching for more min value that is greater than or equal to x
int findCeil(int v[],int n,int x){
    sort(v,v+n);
    int res = -1;
    if(v[0] > x) return v[0];
    if(v[n-1] < x) return -1;
    int mid;
    int low = 0,high = n-1;
        while(low <= high){
             mid = low + (high - low)/2;
            
            if(v[mid] == x) return v[mid];
            else if(v[mid] > x) {
                high = mid - 1;
                res = mid;
                }
            else low = mid + 1;
           
        }
        return v[res];
} 
int main(){

int arr[] = {1,2,8,10,11,12,19};
cout<<"Ceil of the value x is : "<<findCeil(arr,7,20)<<endl;
return 0;
}
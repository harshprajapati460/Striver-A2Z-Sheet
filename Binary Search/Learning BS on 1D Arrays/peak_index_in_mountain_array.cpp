#include<bits/stdc++.h>
using namespace std;
int Peak_index_array(vector<int>&arr,int n){
    int low = 0,high = arr.size()-1,mid;
        while(low < high){
            mid = low + (high - low)/2;
            if(arr[mid] > arr[mid+1]){
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
}
int main(){

vector<int>arr = {1,2,3,4,5,2,1};
int n = arr.size();
cout<<"Peak index is : "<<Peak_index_array(arr,n)<<endl;
return 0;
}
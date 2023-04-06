#include<bits/stdc++.h>
using namespace std;
int BS(vector<int>&arr,int key){
    int low = 0,high = arr.size()-1;
    int mid ;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            high = mid-1;
        }
        else low = mid+1;
    }

return -1;
}
int main(){

vector<int>arr = {2,3,5,6,7,9,10,19,21,23};
cout<<BS(arr,19)<<endl;
return 0;
}
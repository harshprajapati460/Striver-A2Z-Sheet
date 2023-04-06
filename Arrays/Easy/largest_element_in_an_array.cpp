#include<bits/stdc++.h>
using namespace std;
int largest_element(vector<int>&arr,int n){
    int mx = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        mx = max(mx,arr[i]);
    }
    return mx;
}
int main(){

vector<int>arr = {1, 2, 20, 3, 2, 4, 5};
int n = arr.size();
cout<<largest_element(arr,n)<<endl;
return 0;
}
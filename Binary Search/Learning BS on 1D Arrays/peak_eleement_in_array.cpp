#include<bits/stdc++.h>
using namespace std;
// Method - 1
// This is a brute force approach. We traverse each element and check whether it is greater than or equal to its neighbours.
// If we find one, we return it.
// Else we move on.
// Time complexity O(N)

// Method - 2 Binary search
// So we are going to use binary search. As usual we find a middle element and if it is a peak, then we are done.
// If not we follow a greater element. That is we shrink the binary search to one half. To be precise, if the left element is a greater one, we then do binary search only on the left half.
// Else(the right element must be a greater one), we search on the right half.
// Ultimately, we’ll end up with one of the peaks.
// Time Complexity O(log(n))
int Peak_element(vector<int>&arr,int n){
    int low =0,high = n-1,mid;
    int ans = -1;
    while(low <= high){
        mid  = low + (high - low)/2;
       
        if(mid > 0 && mid < n - 1){
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                ans = mid;
                return mid;
            }
            else if(arr[mid-1] > arr[mid]){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        else if(mid == 0) {
            if(arr[0] > arr[1]) return 0;
            else return 1;
        }
        else if(mid == n-1){
            if(arr[n-1] > arr[n-2]) return n-1;
            else return n-2;
        }
    }
    return ans;
    
}
int main(){

vector<int>arr = {3, 4, 4, 4, 10, 1};
cout<<"Peak Element is : "<<Peak_element(arr,arr.size())<<endl;
return 0;
}
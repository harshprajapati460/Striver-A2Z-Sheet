#include<bits/stdc++.h>
using namespace std;
//We divide the array into parts. It is done using two pointers, low and high, and dividing the range between them by 2. This gives the midpoint of the range. Check if the target is present in the midpoint, calculated before, of the array. If not present, check if the left half of the array is sorted. This implies that binary search can be applied in the left half of the array provided the target lies between the value range. Else check into the right half of the array. Repeat the above steps until low <= high. If low > high indicates we have searched the array and the target is not present hence return -1. Thus, it makes search operations less as we check the range first and then perform searching in possible ranges which may have target values.
// Time compelexity O(log(N))
int Search_rotated_array(vector<int>&arr,int n,int target){
      int low = 0,high = n-1,mid;
      while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid] == target) return mid;
          
        if(arr[mid] >= arr[low]){
            if(target <= arr[mid] && target >= arr[low]){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        else {
                if(target >= arr[mid] && target <= arr[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
        }
      }
      return -1;
}
int main(){

vector<int>arr = {1,0,1,1,1};
int n = arr.size();
cout<<"Target element is : "<<Search_rotated_array(arr,n,0)<<endl;
return 0;
}
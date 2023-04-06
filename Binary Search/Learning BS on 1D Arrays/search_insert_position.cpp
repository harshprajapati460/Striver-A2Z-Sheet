#include<bits/stdc++.h>
using namespace std;
 int searchInsert(vector<int>& nums, int target) {
        int res = -1;
        int n = nums.size();
        if(nums[0] > target) return 0;
        if(nums[n-1] < target) return n;

        int start = 0,end= n-1,mid;
        while(start <= end){
           mid = start + (end-start)/2;

           if(nums[mid] == target) return mid;
           else if(nums[mid] > target){
             res = mid;
             end = mid - 1;
           } 
           else  start = mid + 1;
           
        }
        return res;
    }
int main(){

vector<int>arr = {1,2,8,10,11,12,19};
cout<<"Inset Position of the value x or smallest value greater than equal to x is : "<<arr[searchInsert(arr,7)]<<endl;
return 0;
}
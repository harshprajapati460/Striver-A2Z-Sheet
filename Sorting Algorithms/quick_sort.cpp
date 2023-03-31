#include<bits/stdc++.h>
using namespace std;
// // Explanation 
// Step 1 -> Pick a pviot 
//           1st element
//           last element
//           medium element
//           Any element
// step 2 -> iterate two pointer til arr[i] <= pivot and arr[j] >= pivot (Smaller on the left and larger on the right)     
     
int partition(vector<int>&arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high-1) i++;

        while(arr[j] >= pivot && j >= low+1) j--;

        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>&arr,int low,int high){
    if(low < high){
        int pindex = partition(arr,low,high);

        qs(arr,low,pindex);
        qs(arr,pindex+1,high);
    }
}
int main(){

vector<int> arr = {8,2,31,2,13,4,5,6,7,2,10};
int N = arr.size();
cout<<"Array before merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
cout<<endl;

qs(arr,0,N-1);
cout<<"Array after merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
return 0;
}

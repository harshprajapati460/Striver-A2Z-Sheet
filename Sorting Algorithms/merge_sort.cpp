#include<bits/stdc++.h>
using namespace std;

// It has basically two function 1.Merge_sort this function split the array hypothetically into one units and 2. Funct merge() merge these two array in sorted order
// Time complexity is O(NlogN) && Space complexity is S(N) Temperary array 
void merge(vector<int>&arr,int low,int mid,int high){
    
    vector<int>temp;
    int i = low;
    int j = mid+1;
    
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= high){
        temp.push_back(arr[j++]);
    }
    for(int i=low ;i <= high;i++){
        arr[i] = temp[i-low];
    }
    

}

void Merge_sort(vector<int>&arr,int low,int high){
    if(low >= high){
        return ;
    }
    int mid = (low+high)/2;
    Merge_sort(arr,low,mid);
    Merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){

vector<int> arr = {8,2,31,2,13,4,5,6,7,2,10};
int N = arr.size();
cout<<"Array before merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
cout<<endl;

Merge_sort(arr,0,N-1);
cout<<"Array after merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
return 0;
}
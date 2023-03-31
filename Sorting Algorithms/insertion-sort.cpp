#include<bits/stdc++.h>
using namespace std;
// Insert the element 
// Simply swap if arr[j-1] > arr[j] till j > 0 
// Time complexity O(n^2) S(1)
void insertion_sort(vector<int>&arr,int N){
    for(int i=0;i<N;i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j] ){
            swap(arr[j],arr[j-1]);
            j--;
        }
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

insertion_sort(arr,N);
cout<<"Array after merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
return 0;
}
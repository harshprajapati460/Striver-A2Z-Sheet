#include<bits/stdc++.h>
using namespace std;
//  Simple Select the minimum and swap it with first unorded element of array
// Time Complexity O(N^2) Space complexity S(1)
void selection_sort(vector<int>&arr,int N){
    for(int i=0;i<N;i++){
        int mini = i;
        for(int j = i+1;j<N;j++){
          if(arr[j] < arr[mini]){
            mini = j;
          }
        }
        swap(arr[i],arr[mini]);
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

selection_sort(arr,N);
cout<<"Array after merge sort : ";
for(auto it:arr){
    cout<<it<<" ";

}
return 0;
}
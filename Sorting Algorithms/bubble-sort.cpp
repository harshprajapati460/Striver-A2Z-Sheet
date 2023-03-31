#include<bits/stdc++.h>
using namespace std;
// Simple swap if arr[j-1] > arr[j] 
// Repeat untill the array is sorted
// Time complexity O(N^2) Space complexity S(1)
void bubble_sort(vector<int>&arr,int N)
{
    int i = 1;
    while(i < N){
        int j = i;
        while(j < N){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            j++;
        }
        i++;
    }
}
    int main(){

vector<int> arr = {8,2,31,2,13,4,5,6,7,2,10};
int N = arr.size();
bubble_sort(arr,N);
for(auto it:arr){
    cout<<it<<" ";
}
return 0;
}
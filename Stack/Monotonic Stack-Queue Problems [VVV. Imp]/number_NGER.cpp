#include<bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY O(queries*N) SPACE COMPLEXITY S(1)
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int>ans;
       int count = 0;
       for(int i = 0; i < queries ; i++){
           count = 0;
           int curr = indices[i];
           for(int j = curr+1 ; j < n ; j++){
               if(arr[j] > arr[curr]){
                   count++;
               }
              
           }
            ans.push_back(count);
       }
       return ans;
    }
int main(){

 vector<int>arr = {3, 4, 2, 7, 5, 8, 10, 6};
 vector<int>q = {0,5};
 vector<int>ans = count_NGE(8,arr,2,q);
 for(auto it:ans){
    cout<<it<<" "; 
 }

return 0;
}
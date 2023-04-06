#include<bits/stdc++.h>
using namespace std;
// Method - 1 Using binary search method 
// steps :
//   1. for every row apply bs
//   2. check if mid == 1 then it can be starting point of 1 so high  = mid-1 and ans = minstd_rand ||
//   if mid == 0 1 is present on the right side low = mid + 1
//   3. if( low > high ) break the loop return m - ans --> size_of_wow - first index of 1 
//   4. store maximum for every rwo and index if max < temp change the index 
//   5. return the index 

// Time complexity Since we are iterating full array one and applying binary search on all of them so O(Nlog(M))
// Space compelxity S(1)
int bs(vector<int>v, int m){
        int start=0, end=m-1, ans=m;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(v[mid]==1){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return m-ans;
    }

    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int sum=0, j=-1;
        for(int i=0; i<n; i++){
            int temp = bs(arr[i], m);
            if(temp>sum){
                sum=temp;
                j=i;
            }
        }
        return j;
    }

// Method - 2 iterating from back 
// Traverse every row and for every row traverse it from back
// if arr[i][j] == 1 then store and col--
// else arr[i][j] == 0 so break check the next rwo and the max value is already stored in the row variable
//Time complexity O(Log(M+N))
//
int rowWithMax1s_method_2(vector<vector<int>>arr, int n, int m) {
        // code here
       int col=m-1;
       int row=-1;
    //   Traversing row by row
       for(int i=0;i<n;i++)
       {
        //   last column to first
           for(int j=col;j>=0;j--)
           {
               if(arr[i][j]==1)
               {
                   row=i;
                //   We will not see same column again
                   col--;
               }
            //   if you see zero 0 then skip that row
            else{
                break;
            }
           }
       }
       return row;
    }

int main(){

vector<vector<int>>arr = {{0,0,1,1},{0,1,1,1},{0,0,0,1},{0,0,1,1}};
cout<<"Row with Highest 1's : "<<rowWithMax1s(arr,4,4)<<endl;

cout<<"Row with Highest 1's : "<<rowWithMax1s_method_2(arr,4,4)<<endl;
return 0;
}
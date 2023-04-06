#include<bits/stdc++.h>
using namespace std;
// Initially consider the start=0 and the end=n-1 pointers and the result as -1.

// Till start does not crossover end pointer compare the mid element 

// If the mid element is equal to the key value, store the mid-value in the result and move the start pointer to mid+1(move leftward)
// Else if the key value is less than the mid element then end= mid-1(move leftward)
// Else do start = mid+1 (move rightwards)
// Time Complexity: O(log n)

// Space Complexity: O(1)

	int FindOcurrence(vector<int>&arr,int n,int target,bool tog){
        int start = 0,end = n - 1,mid;
        int ans =-1;
        while(start <= end){
            mid = start + (end-start)/2;
            if(arr[mid] > target){
                end = mid - 1;

            }
            else if(arr[mid] < target){
                start = mid + 1;
            }
            else {
                ans = mid;
                if(tog) end = mid - 1;
                else start = mid + 1;
            }

        }
        return ans;
}
int count(vector<int>&arr, int n, int x) {
	    int start_idx = FindOcurrence(arr,n,x,true);
        int end_idx = FindOcurrence(arr,n,x,false);
        if(start_idx == -1) return 0;
        return end_idx - start_idx + 1; 
	    // code here
	}

int main(){

vector<int>arr = {1, 3, 5, 5, 5, 5, 5, 123, 125};

cout<<"Count of given target in the array is : "<<count(arr,arr.size(),5)<<endl;

return 0;
}
#include<bits/stdc++.h>
using namespace std;
int findFloor(vector<long long> v, long long n, long long x){
    int res = -1;
        if(v[0] > x ) return -1;
        if(v[n-1] < x) return n-1;
        
        int low = 0,high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(v[mid] == x) return mid;
            else if(v[mid] > x) high = mid - 1;
            else {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
        // Your code here
        
    }
int main(){

vector<long long>arr = {1,2,8,10,11,12,19};
cout<<"Floor of the value x is : "<<findFloor(arr,7,11)<<endl;
return 0;
}
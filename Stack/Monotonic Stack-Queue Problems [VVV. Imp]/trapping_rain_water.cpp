#include<bits/stdc++.h>
using namespace std;
// TIME AND SPACE COMPLEXITY O(N) AND S(4N)
 long long trappingWater(int arr[], int n){
        // code here
        vector<int>lmax(n,0),rmax(n,0);
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,arr[i]);
            lmax[i] = maxi;
        }
        maxi = -1;
        for(int i = n-1; i >= 0 ; i--){
            maxi = max(maxi,arr[i]);
            rmax[i] = maxi;
        }
        vector<int>water(n,0);
        for(int i= 0 ; i < n ;i++){
            water[i] = min(lmax[i],rmax[i]) - arr[i];
        }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += water[i];
        }
        return ans;
    }
int main(){
int arr[] = {3,0,0,2,0,4};

cout<<trappingWater(arr,6)<<endl;
return 0;
}
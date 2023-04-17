#include<bits/stdc++.h>
using namespace std;
// TIME AND SPACE COMPLEXITY IS O(N) S(5N) TWO STACK,WIDTH,LEFT,RIGHT
// PROBLEM LINK : https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// gfg : https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-rectangular-area-in-a-histogram
vector<int> NSR(vector<int>&arr,int n){
    vector<int>ans;
    stack<int>s;
    for(int i = n-1;i >= 0; i--){
        if(s.size() == 0){
            ans.push_back(n);
        }
        else if(s.size() > 0 && arr[s.top()] < arr[i]){
              ans.push_back(s.top());
        }  
        else if(s.size() > 0 && arr[s.top()] >= arr[i]){
            while(s.size() > 0 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                ans.push_back(n);
            }
            else {
                ans.push_back(s.top());
            }  
        }
        s.push(i);
          }
          reverse(ans.begin(),ans.end());
    return ans;
    }
    
    vector<int> NSL(vector<int>&arr,int n){
    vector<int>ans;
    stack<int>s;
    for(int i = 0;i < n; i++){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() > 0 && arr[s.top()] < arr[i]){
              ans.push_back(s.top());
        }  
        else if(s.size() > 0 && arr[s.top()] >= arr[i]){
            while(s.size() > 0 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }  
        }
        s.push(i);
          }
         
    return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>left = NSL(arr,n);
        vector<int>right = NSR(arr,n);
        vector<int>width(n,0);
        for(int i = 0 ; i < n; i++){
            width[i] = arr[i] * (right[i] - left[i] - 1);
            
        }
        return *max_element(width.begin(),width.end());
    }
int main(){

vector<int>arr = {2,1,5,6,2,3};
int n = arr.size();
cout<<largestRectangleArea(arr);
return 0;
}
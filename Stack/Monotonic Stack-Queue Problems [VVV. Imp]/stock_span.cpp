#include<bits/stdc++.h>
using namespace std;
// TIME AND SPACE COMPLEXITY IS O(N) & S(2N)

vector<int> NGL_1(vector<int>&arr,int n){
    vector<int>ans;
    stack<pair<int,int>>s;
    for(int i = 0;i<n;i++){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first > arr[i]){
            ans.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top().second);
            }

        }
        s.push({arr[i],i});
    }
    for(int i = 0 ; i < ans.size(); i++){
        ans[i] = i - ans[i];
    }
    return ans;
    }

// TIME AND SPACE COMPLEXITY O(N) & S(N)

vector<int> NGL_2(vector<int>&arr,int n){
    vector<int>ans;
    stack<int>s;
    for(int i = 0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && arr[s.top()] > arr[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() && arr[s.top()] <= arr[i]){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }

        }
        s.push(i);
    }
    for(int i = 0 ; i < ans.size(); i++){
        ans[i] = i - ans[i];
    }
    return ans;
    }

int main(){
vector<int>arr = {100,80,60,70,60,75,85};
int n = arr.size();
for(auto it:arr){
    cout<<it<<" ";
}
cout<<endl;
vector<int>ans = NGL_2(arr,n);
for(auto it:ans){
    cout<<it<<" ";
}
return 0;
}
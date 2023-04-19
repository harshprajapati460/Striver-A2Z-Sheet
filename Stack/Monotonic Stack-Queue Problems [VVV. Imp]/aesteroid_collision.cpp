#include<bits/stdc++.h>
using namespace std;
 vector<int> asteroidCollision(int N, vector<int> &a) {
        // code here
        stack<int>s;
        vector<int>ans;
        for(auto x : a){
            if(s.empty()){
                s.push(x);
            }
            else{
                if(x > 0){
                    s.push(x);
                }
                else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(x)){
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(x)){
                    s.pop();
                    continue;
                }
                 if(!s.empty() && s.top()>abs(x)){
                      continue;
                  }
                 s.push(x);
                }
            }
           
        }
    
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){

 vector<int>arr = {2,2,3,4,-2,2,-23,-3};
 int n = arr.size();
 vector<int>ans = asteroidCollision(n,arr);
 for(auto it:ans){
    cout<<it<<" ";
 }
 
return 0;
}
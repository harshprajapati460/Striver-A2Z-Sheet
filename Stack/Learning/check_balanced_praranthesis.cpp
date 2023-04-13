#include<bits/stdc++.h>
using namespace std;
bool ispar(string x)
    {
        // Your code here
        stack<char> s;
    
        for(int i=0;i<x.length();i++){
            
            if(x[i]==')' && !s.empty() && s.top() == '(')
                s.pop();
            else if(x[i] == ']' && !s.empty() && s.top() == '[')
                s.pop();
            else if(x[i] == '}' && !s.empty() && s.top() == '{')
                s.pop();
            else if( x[i] == '(' || x[i] == '{' || x[i] == '[')
                s.push(x[i]);
            else 
                return false;
        }
        if(s.empty()) return true;
        return false;
    }


int main(){

string s = "{(])}";
string s1 = "[()]{}{[()()]()}";
cin >> s;
cout<<s<<" ";
if(ispar(s)){
    cout<<" Balanced "<<endl;
}
else {
    cout<<" Not Balanced "<<endl;
}
cout<<endl;
cout<<s1<<" ";
if(ispar(s1)){
    cout<<" Balanced "<<endl;
}
else {
    cout<<" Not Balanced "<<endl;
}
return 0;
}
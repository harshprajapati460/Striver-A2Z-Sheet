// PREFIX -> INFIX
// INFIX -> POSTFIX
//TIME AND SPACE COMPLEXITY O(N) &  S(2N) 
#include<bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else return -1;
}
string InfixToPostFix(string x){
    stack<char>s;
    string res = "";
    for(int i=0; i<x.length(); i++){
        if(x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z' || x[i] >= '0' && x[i] <= '9'){
            res += x[i];
        }
        else if(x[i] == '('){
            s.push(x[i]);
        }
        else if(x[i] == ')'){
            while(!s.empty() && s.top() != '('){
                res += s.top();
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            }
        }
        else {
            while(!s.empty() && prec(x[i]) <= prec(s.top())){
                res += s.top();
                s.pop();
            }
            s.push(x[i]);
        }
    }
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    return res;
}
bool isChar(char c){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
            return true;
        }
        else return false;
}
string PreFixToInfix(string x){
   stack<string>s;
   for(int i = x.length()-1 ; i>=0 ; i--){
    if(isChar(x[i])){
        string temp = "";
        temp += x[i];
        s.push(temp);
    }
    else {
         string s1 = s.top();
         s.pop();
         string s2 = s.top();
         s.pop();
         string temp = "("+s1+x[i]+s2+")";
         s.push(temp);
    }
   }
   return InfixToPostFix(s.top());
}

int main(){
 string s = "*+AB-CD";
 cout<<PreFixToInfix(s)<<endl;
int n;
return 0;
}
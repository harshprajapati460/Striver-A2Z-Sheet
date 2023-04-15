// SIMPLE STEPS
// MAKE A isCHAR FUNC THAT TELL THAT CURR CHAR IS CHARACTER OR OPERATOR
// IF X[I] IS A CHARACTER THEN PUSH IT TO THE STACK 
// ELSE POP TWO ITEMS STORE IT AND THEN PUSH THEM WITH CLOSED BRACKED AND PERFECT ARRANGMENT 
//TIME COMPLEXITY O(N) SPACE COMPLEXITY S(N)
#include<bits/stdc++.h>
using namespace std;
bool isChar(char c){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
            return true;
        }
        else return false;
}
string PostFixToInfix(string x){
   stack<string>s;
   for(int i = 0 ; i < x.length() ; i++){
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
         string temp = "("+s2+x[i]+s1+")";
         s.push(temp);
    }
   }
   return s.top();
}

int main(){
 string s = "hm^q^74-^";
 cout<<PostFixToInfix(s)<<endl;
int n;
return 0;
}
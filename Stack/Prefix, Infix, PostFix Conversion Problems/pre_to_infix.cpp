// SIMPLE STEPS
// MAKE A isCHAR FUNC THAT TELL THAT CURR CHAR IS CHARACTER OR OPERATOR
// IF X[I] IS A CHARACTER THEN PUSH IT TO THE STACK 
// ELSE POP TWO ITEMS STORE IT AND THEN PUSH THEM WITH CLOSED BRACKED AND PERFECT ARRANGMENT 
//TIME COMPLEXITY O(N) SPACE COMPLEXITY S(N)
//JUST CHANGE THE POSITION OF S1 AND S2 ACCORTING TO POSTFIX TO INFIX SIMPLE
#include<bits/stdc++.h>
using namespace std;
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
   return s.top();
}

int main(){
 string s = "*-A/BC-/AKL";
 cout<<PreFixToInfix(s)<<endl;

return 0;
}
// STEPS
// IF CHAR THEM PUSH IT TO STACK BY ADDING STRING
// ELSE TAKE TWO STRING S1 AND S2 AND ARRANGE OPERATOR+S2+S1
//TIME AND SPACE COMPLEXITY O(N) &  S(2N)
// Read the Postfix expression from left to right
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack 
// Create a string by concatenating the two operands and the operator before them. 
// string = operator + operand2 + operand1 
// And push the resultant string back to Stack
// Repeat the above steps until end of Postfix expression. 
#include<bits/stdc++.h>
using namespace std;
bool isChar(char c){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
            return true;
        }
        else return false;
}
string PostFixToPrefix(string x){
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
         string temp = x[i]+s2+s1;
         s.push(temp);
    }
   }
   string ans = "";
   while(!s.empty()){
    ans += s.top();
    s.pop();
   }
   return ans;
}


int main(){
 string s = "AB+CD-*";
 cout<<PostFixToPrefix(s)<<endl;
int n;
return 0;
}
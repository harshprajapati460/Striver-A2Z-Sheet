// STEPS 
//1. IF OPERAND -> ADD TO ANS STRING OR PRINT IT
//2. IF '(' -> PUSH TO STACK
//3. IF ')' -> POP FROM STACK AND ADD TO ANS STIRNG TILL '(' IS FOUND
//4. IF OPERATOR -> POP FROM STACK AND PRINT UNTIL AN OPERATOR WITH LESS PREC IS FOUND
// Note * CEHCK FOR NUMBER IF THERE IS A NUMBER 0-9 THEN ADD IT TO ANS
// Time Complexity: O(N)

// Space Complexity: O(N) for using the stack
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

int main(){
 string s = "h^m^q^(7-4)";
 cout<<InfixToPostFix(s)<<endl;
int n;
return 0;
}
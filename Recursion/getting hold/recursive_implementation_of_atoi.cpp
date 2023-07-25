// #include <bits/stdc++.h> 
// int solve(string str,int &ans){
//     if(str.length() == 0){
//         return ans;
//     }
//     int x = str[0] - '0';
//     if(x >= 0 && x <= 9){
//         ans = ans*10 + x;
//     }
//     str.erase(str.begin()+0);
//     solve(str,ans);
// }
// int atoi(string str) {
//    int minus = 0;
//    if(str[0] == '-') minus++;
//    int ans = 0;
//    solve(str,ans);
//    if(minus == 0) return ans;
//    else return -ans;
//     // Write your code here.
// }

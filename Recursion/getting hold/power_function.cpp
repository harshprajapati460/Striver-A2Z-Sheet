// double solve(double x,int n){
//     if(n == 0){
//         return 1;
//     }
//     if(n%2 == 0){
//         return solve(x,n/2) * solve(x,n/2); 
//     }
//     else {
//         return x * solve(x,n/2) * solve(x,n/2);
//     }
// }
// double myPow(double x, int n) {
//     // Write Your Code Here
//     int minus = 0;
//     if(n < 0){
//         minus = 1;
//         n = -n;
//     }
//     double ans =solve(x,n);
//     if(minus) return 1.0/ans;
//     else return ans;
// }
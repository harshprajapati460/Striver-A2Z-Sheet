// bool check(int n,int sum,int digit){
//         if(n == 0){
// 			return true;
// 		}
		
// 		if(n%10 <= sum || n%10 == digit) return false;
// 		return check(n/10,sum+n%10,digit);
// }
// vector<int> goodNumbers(int a, int b, int digit) {
// 	// Write your code here.
// 	vector<int>ans;
// 	for(int i=a; i<=b; i++){

// 		if(i%10 != digit && check(i/10,i%10,digit)){
// 			ans.push_back(i);
// 		}
// 	}
// 	return ans;
// }
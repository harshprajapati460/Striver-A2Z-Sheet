// Approach: This problem can be solved using Greedy Approach. Below are the steps: 
//Method - 1
// For the property of the circular array to be valid append the given array elements to the same array once again.
// For Example: 

// Let arr[] = {1, 4, 3} 
// After appending the same set of elements arr[] becomes 
// arr[] = {1, 4, 3, 1, 4, 3} 

// Find the next greater element till N elements in the above array formed.
// If any greater element is found then print that element, else print “-1”.

//This approach takes of O(n2) time but takes extra space of order O(n)
#include<bits/stdc++.h>
using namespace std;
void printNGE1(int A[], int n)
{
    // Formation of circular array
    int arr[2 * n];
    // Append the given array element twice
    for (int i = 0; i < 2 * n; i++)
        arr[i] = A[i % n];
    int next, i, j;
    // Iterate for all the elements of the array
    for (i = 0; i < n; i++) {
        // Initialise NGE as -1
        next = -1;
        for (j = i + 1; j < 2 * n; j++) {
            // Checking for next greater element
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        // Print the updated NGE
        cout << next << ", ";
    }
}
//A space-efficient solution is to deal with circular arrays using the same array. If a careful observation is run through the array, then after the n-th index, the next index always starts from 0 so using the mod operator, we can easily access the elements of the circular list, if we use (i)%n and run the loop from i-th index to n+i-th index, and apply mod we can do the traversal in a circular array within the given array without using any extra space.
// Time Complexity: O(n2) 
// Auxiliary Space: O(1)
void printNGE2(int A[], int n)
{
    int k;
    for(int i = 0; i < n; i++)
    {
        // Initialise k as -1 which is printed
        // when no NGE found
        k = -1;
        for(int j = i + 1; j < n + i; j++)
        {
            if (A[i] < A[j % n])
            {
                cout <<" "<< A[j % n];
                k = 1;
                break;
            }
        }
        // Gets executed when no NGE found
        if (k == -1)
            cout << "-1 ";
    }
}
//Method 3rd: The method uses the same concept used in method 2 for circular Array but uses Stack to find out the next greater element in O(n) time complexity where n is the size of the array. For better understanding, you can see the next greater element.
//Time Complexity: O(N)
// Auxiliary Space: O(N)

void nextGreaterElement(int arr[],int n) {
        // code here
       
        stack<int>s;
        vector<int>v(n);
        int ele;
        for(int i = 0 ; i < 2*n; i++){
            ele = arr[i%n];
            while(!s.empty() && arr[s.top()] < ele){
                 v[s.top()] = ele;
                s.pop();
            }
            if(i < n){
                s.push(i%n);
            }
        }
        while(!s.empty()){
            v[s.top()] = -1;
            s.pop();
        }
        for(auto it:v){
            cout<<it<<" ";
        }
        
    }

//  Method :- 4 
// In method 3, next greater element is calculated by traversing the array from backward (end) but we can also do the same in forward (start) traversal.   
 void printNGE4(int nums[], int n)
{
    // Stores the next greater element for index i.
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
        while (!s.empty() && nums[s.top()] < nums[i % n]) {
            ans[s.top()] = nums[i % n];
            s.pop();
        }
        if (i < n)
            s.push(i);
    }
    for (auto it : ans)
        cout << it << " ";
}
 
 int main(){
  int arr[] = {4, -2, 5, 8};
  printNGE4(arr,4);
  
return 0;
}
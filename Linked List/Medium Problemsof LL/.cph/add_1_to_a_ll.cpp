#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = nullptr;

    }

};
// Method - 1 Make the number represented by ll ad add one to it and then make the ans linked list for it
// too much operation

// Method - 2
//  
Node *reverse(Node *head)
{
    Node * prev = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addOneUtil(Node *head){
   Node* res = head;
    Node *temp;
 
    int carry = 1, sum;
 
    while (head != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of head list (if there is a
        // next digit)
        sum = carry + head->data;
 
        // update carry for next calculation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        head->data = sum;
 
        // Move head and second pointers to next nodes
        temp = head;
        head = head->next;
    }
 
    // if some carry is still there, add a new node to
    // result list.
    if (carry > 0)
        temp->next = new Node(carry);
 
    // return head of the resultant list
    return res;
 }


Node *Add_1(Node *head){
 head = reverse(head);
 
    // Add one from left to right of reversed
    // list
    head = addOneUtil(head);
 
    // Reverse the modified list
    return reverse(head);
}
void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
 
 Node *head = new Node(1);
 Node *Second = new Node(2);
 Node *Third = new Node(3);
 Node *Four = new Node(4);
 Node *Five  = new Node(5);
 head->next = Second;
 Second->next = Third;
 Third->next = Four;
 Four ->next = Five;


 
print(head);
print(Add_1(head));
return 0;
}
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

// Find loop by  Floyd’s Cycle-Finding Algorithm:
//This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. The faster one is called the faster pointer and the other one is called the slow pointer.
//  Traverse linked list using two pointers.
// Follow the steps below to solve the problem:
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.
//Time complexity: O(N), Only one traversal of the loop is needed.
// Auxiliary Space: O(1). 

// 2(L1+L2) = L1+L2+nC. This makes the equation to

// L1+L2 = nC. Moving L2 to the right side 

// L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.
Node * find_starting_node(Node *head){
   
    Node *slow =head;
    Node *fast = head;
    while(slow  && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast){
              slow = slow->next;
              fast = fast->next;
              if(slow == fast) return slow;
            }
        }

    }
    Node *N = new Node(-1);
    return N;
    
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
 //Five->next = Third;

cout<<find_starting_node(head)->data<<endl;

return 0;
}
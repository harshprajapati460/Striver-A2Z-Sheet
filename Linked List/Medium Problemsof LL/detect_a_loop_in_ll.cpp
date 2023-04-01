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
// There are many methods to find loops in Linked List
// Method - 1 Use a dummy node and point every pointer to it and check whether curr->next == dummy if yes then there's a loop
// Step 1. Create a dummy node
// Step 2. Iterate from head and point every curr->next to dummy 
// Step 3. Check if curr == nullptr then there no loop return fasle
// Step 4. if curr->next already == dummy node then there's a loop and return true
// Time complexity O(N) But the linked list will be distroyed

bool Method_1(Node *head){
    Node *dummy = new Node(1);
    Node *curr = head;
    while(curr != nullptr){
        if(curr->next == nullptr) return false;
        if(curr->next == dummy) return true; //Loop is present
        Node *next = curr->next;
        curr->next = dummy;
        curr = next;
    }
    return false;
}

// Method-2   Using Hashmap or Map
// Simply store the next pointers of every node in the hash and check if its already present or not if yes then loop is present
// Step 1. Create a map of <Node *>
// Step 2. Iterate over the Linked List and check if Node->next is present in Map or not 
// if yes return true loop is present 
// At the end return false if curr->next == nullptr
// Time complexity will be O(N) && Space complexity will be S(N) 

bool Method_2(Node *head){
   set<Node *>map;
   Node *curr = head;
   while(curr != nullptr){
    if(curr->next == nullptr) return false;

    if(map.find(curr->next) != map.end()) return true;
    else {
        map.insert(curr->next);
    }
    curr = curr->next;
   }
   return false;
}
// Method - 3  Floyd’s Cycle-Finding Algorithm:
//This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. The faster one is called the faster pointer and the other one is called the slow pointer.
//  Traverse linked list using two pointers.
// Follow the steps below to solve the problem:
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.

bool Method_3(Node *head){
    Node *slow =head;
    Node *fast = head;
    while(slow  && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;

    }
    return false;
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

//  if(Method_1(head)){
//    cout<<"Loop is present"<<endl;
//  }
//  else cout<<"Loop is not present"<<endl;

 if(Method_2(head)){
   cout<<"Loop is present"<<endl;
 }
 else cout<<"Loop is not present"<<endl;

  if(Method_3(head)){
   cout<<"Loop is present"<<endl;
 }
 else cout<<"Loop is not present"<<endl;

return 0;
}
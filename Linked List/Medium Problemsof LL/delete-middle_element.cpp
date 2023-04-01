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

 // Find middle delete it
Node *delete_middle(Node *head){
    int count = 0;
    Node *slow =head;
    Node *fast = head->next;
  
   while(fast != nullptr && fast->next != nullptr){
       slow = slow->next;
       fast = fast->next->next;
   }
   slow->data = slow->next->data;
   Node *n = slow->next;
   slow->next = n->next;
   delete n;
   return head; 
    
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
print(delete_middle(head));

return 0;
}
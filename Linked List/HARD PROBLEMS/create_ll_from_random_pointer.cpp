#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *random;
    Node (int x){
        data = x;
        next = nullptr;
        random = nullptr;
    }

};
void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->data);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }

int main(){
 
Node *head = new Node(4);

head->next  = new Node(2);
head->next->next = new Node(1);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(3);
head->random = head->next->next;
head->next->next->next->next->next->next = new Node(9);


print(head);
print(copyRandomList(head));

return 0;
}
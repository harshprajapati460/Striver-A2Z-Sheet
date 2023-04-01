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
void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *Sum_of_two_list(Node *head1,Node *head2){
      Node *dummy = new Node(0);
      Node *curr = dummy;
      int carry = 0;
      while(head1!= nullptr || head2!= nullptr || carry > 0){

        int sum = 0;
        sum += carry;
        if(head1 != nullptr){
             sum += head1->data;
             head1 = head1->next;
        }
        if(head2 != nullptr){
             sum += head2->data;
             head2 = head2->next;
        }
           
           Node *n = new Node(sum%10);
           carry = sum/10;
           curr->next  = n;
           curr = curr->next;
      }
      return dummy->next;
}

int main(){
 
 // List 1 =  4->1->7
 // List 2 =  5->4->9
 // sum = 714+945 = 1659
// newhead = 1->6->5->9
Node *head1 = new Node(4);
head1->next = new Node(1);
head1->next->next = new Node(7);
print(head1);
Node *head2 = new Node(5);
head2->next = new Node(4);
head2->next->next = new Node(9);
print(head2);

Node *newhead =Sum_of_two_list(head1,head2);
print(newhead);

return 0;
}
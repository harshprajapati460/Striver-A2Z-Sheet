#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = nullptr;

    }

};

Node *Reverse_recursive(Node *head){
    if(!head || !head->next) return head;
    Node *newhead = Reverse_recursive(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = nullptr;
    return newhead;
}
Node *Reverse_iterative(Node *head){
    if(head == nullptr || head->next == nullptr) return head;
    Node *prev = NULL,*curr = head;
    while(curr != nullptr){
        Node *Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
     
}

void print(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int main(){
    //LL 4->2->1->4->5->3->9
Node *head = new Node(4);
head->next  = new Node(2);
head->next->next = new Node(1);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next = new Node(9);


print(head);
Node *newhead = Reverse_recursive(head);
print(newhead);

return 0;
}
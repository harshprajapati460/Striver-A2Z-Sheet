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
// Method -1 count the number of nodes (C) and delete (C-n)th node but it will take two loops 
//Method -2 Take two pointer one from head and one from nth node next from head when second pointer reches null then we will be on nth node form back delete it 
// Time comlexity O(N) single loop S(1)


Node *remove_nth_node(Node *head,int x){
    Node *curr1 = head;
    Node *curr2 = head;
    while(x-->0){
        curr2 = curr2->next;
    }
    while(curr2->next != nullptr){
        curr2 = curr2->next;
        curr1 = curr1->next;

    }
    Node *n = curr1->next;
    curr1->next = n->next;
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
 //Five->next = Third;
print(head);
cout<<remove_nth_node(head,3)<<endl;
print(head);
return 0;
}
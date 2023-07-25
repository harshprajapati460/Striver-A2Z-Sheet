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

//Method 1 
//  Simple count length of both list 
//  iterate the diff let say d of one head bigger one
//  then iterate till they are equal
// Time complexity O(N) ;
int length(Node *head){
    int c = 0;
    Node *temp = head;
    while(temp){
        c++;
        temp = temp->next;

    }
   return c;
}
Node *get_intersection(Node *head1,Node *head2,int d){

    while(d-->0){
     head1 = head1->next;
    }
    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;

    }
    return head1;
}
Node *intersection_point(Node *head1,Node *head2){
    int c1 = length(head1);
    int c2 = length(head2);
    int d;
    if(c1 - c2 > 0){
        return get_intersection(head1,head2,c1-c2);
    }
    else {
        return get_intersection(head2,head1,c2-c1);

    }
}

void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Method - 2 
// Two pointer a and b
// change their head if either of them visit nullptr
// 

Node *intersection_point_method_2(Node *head1,Node *head2){
   Node *a = head1;
   Node *b = head2;
   while(a != b){
    if(a == nullptr) {
        a = head2;
    }
    if(b == nullptr){
         
        b = head1;
    } 
    a = a->next;
    b = b->next;
   }
   return a;
}
int main(){
 
 Node *head1 = new Node(10);
 Node *Second = new Node(20);
 Node *Third = new Node(30);
 Node *Four = new Node(40);
 Node *Five  = new Node(50);

 head1->next = Second;
 Second->next = Third;
 Third->next = Four;
 Four ->next = Five;
 Node *head2 = new Node(60);
 head2->next = new Node(70);
 head2->next->next = new Node(80);
 head2->next->next->next = new Node(90);
 head2->next->next->next->next = new Node(100);
 Node *common = new Node(110); // Common 
 head2->next->next->next->next->next = common;
 Five->next = common;


common->next = new Node(120);
common->next->next = new Node(130);
common->next->next->next = new Node(140);
common->next->next->next->next = new Node(150);

  
print(head1);
print(head2);
cout<<"Intersection point is : "<<intersection_point(head1,head2)->data<<endl;

cout<<"Intersection point is : "<<intersection_point_method_2(head1,head2)->data<<endl;
return 0;
}
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

Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = nullptr,*Next = nullptr;
    while(curr){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
Node *middle_element(Node *head){
    if(head == nullptr || head->next == nullptr) return head;

    Node *slow = head,*fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
bool check_palindrome(Node *head){
    Node *middle = middle_element(head);
    Node *half = middle->next;
    middle->next = nullptr;

    half = reverse(half);
    Node *temp = head;
    while(temp && half){
        if(temp->data != half->data) return false;
        temp = temp->next;
        half = half->next;
    }
    return true;
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
 Node *head1 = new Node(1);
 Node *Second1 = new Node(2);
 Node *Third1 = new Node(3);
 Node *Four1 = new Node(4);
 Node *Five1  = new Node(5);
//Five->next = Five1;
 Five1->next = Four1;
 Four1->next = Third1;
 Third1->next = Second1;
 Second1->next = head1;


 
print(head);
cout<<check_palindrome(head)<<endl;
return 0;
}
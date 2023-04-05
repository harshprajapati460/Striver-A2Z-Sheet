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

Node* rotateRight(Node* head, int k) {
        if(head == nullptr) return head;
        Node *tail = head;
        int count = 1;
        while(tail->next != nullptr){
            count++;
            tail = tail->next;
        }
        k = k%count;
        tail->next = head;
        Node *curr = head;
        k = count-k;
        while(k--> 1){
         curr = curr->next;

        }
        head =curr->next;
        curr->next = nullptr;
        return head;
    }

int main(){
 
Node *head = new Node(4);
head->next  = new Node(2);
head->next->next = new Node(1);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next = new Node(9);

int k = 3;
print(head);

print(rotateRight(head,k));


return 0;
}
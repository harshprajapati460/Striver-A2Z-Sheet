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

Node* reverseKGroup(Node* head, int k) {
        if(head == nullptr || k == 1) return head;
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *pre = dummy, *nex = dummy,*curr = dummy;
        int count = 0;
        while(curr->next != nullptr){
            count++;
            curr = curr->next;
        }

       while(count >= k){
           curr = pre->next;
           nex = curr->next;
           for(int i=1;i<k;i++){
             curr->next = nex->next;
             nex->next = pre->next;
             pre->next = nex;
             nex = curr->next;
           }
           count -= k;
           pre = curr;
       }
       return dummy->next;
    }

int main(){
 
Node *head = new Node(4);
head->next  = new Node(2);
head->next->next = new Node(1);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next = new Node(9);

int k = 2;
print(head);

print(reverseKGroup(head,k));


return 0;
}
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
bool search_element(Node *head,int key){
     Node *temp = head;
     while(temp != nullptr){
        if(key == temp->data) return true;
        temp = temp->next;
     }
     return false;
}
Node *delete_element(Node *head,int key){
    if(head == nullptr) return head;
      Node *temp = head;
      while(temp->next != nullptr){
        if(key == temp->next->data){
            Node *n = temp->next;
            temp->next = n->next;
            delete n;
            
        }
        temp = temp->next;
      }
      return head;
}
int find_length(Node *head){
    int ans = 0;
    Node *temp = head;
    while(temp != nullptr){
        ans++;
        temp = temp->next;
    }
    return ans;
}

void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node *insert_node(Node *head,int x){
    if(head == nullptr){
        return new Node(x);
    }
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node *n = new Node(x);
    temp->next = n;
    return head;

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

head = insert_node(head,12);
print(head);

cout<<search_element(head,12)<<endl;
print(head);
delete_element(head,4);
print(head);
return 0;
}
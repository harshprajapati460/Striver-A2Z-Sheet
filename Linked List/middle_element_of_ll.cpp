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
//  Method - 1 -> Count the no. of elements and divide it by 2 and iterate to it O(N) But Two Loops
//  Method - 2 -> Declare two pointer fast and slow one will move by one and other will move by towctrans
//  when fast reached null or fast->next reaches null then our middle elent is found O(N) Only one loop
int Middle_element(Node *head){
  if(head == NULL ) return 0;
  if(head->next == NULL) return head->data;

  Node *slow =head,*fast = head;
  while(fast->next && fast){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow->data;

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

cout<<"Middle element is : "<<Middle_element(head)<<endl;


int n;
return 0;
}
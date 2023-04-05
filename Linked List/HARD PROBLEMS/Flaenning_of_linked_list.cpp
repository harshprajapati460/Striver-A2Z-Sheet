#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *bottom;
    Node (int x){
        data = x;
        next = nullptr;
        bottom = nullptr;
    }

};
void print(Node *head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->bottom;
    }
    cout<<endl;
}
// We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
// Merge each list chosen using the merge algorithm. The steps are
// Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and temp pointer is to move ahead as we build the flattened list.
// We iterate through the two chosen. Move head from any of the chosen lists ahead whose current pointed node is smaller. 
// Return the new flattened list found.

// Time Complexity: O(N), where N is the total number of nodes present

// Reason: We are visiting all the nodes present in the given list.

// Space Complexity: O(1)

// Reason: We are not creating new nodes or using any other data structure.
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}


int main(){
 
Node *head = new Node(4);
head->bottom = new Node(10);
head->next  = new Node(2);
head->next->next = new Node(1);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(3);
head->next->next->next->next->next->next = new Node(9);


print(head);

print(flatten(head));


return 0;
}
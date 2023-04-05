class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* left = head;
        Node* right = head;
        
        while(right){
            
            if(right->data == left->data) right = right->next;
            else{
                
                left->next = right;
                right->prev = left;
                left = right;
            }
        }
        
        if(left->next != NULL) left->next = NULL;
        
        return head;
    }
};
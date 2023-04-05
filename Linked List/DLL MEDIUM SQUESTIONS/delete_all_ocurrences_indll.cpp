  void deleteAllOccurOfX(struct Node** head, int x) {
         if(!(*head))return;
         struct Node* dummy=new Node();
         dummy->next=*head;
         Node* curr=dummy;
         while(curr){
             if(curr->next&&curr->next->data==x){
                 Node* temp=curr->next;
                 while(temp&&temp->data==x){
                     temp=temp->next;
                 }
                 curr->next=temp;
                 if(temp)
                 temp->prev=curr;
                 curr=temp;
             }
             else curr=curr->next;
         }
         *head=dummy->next;
    }

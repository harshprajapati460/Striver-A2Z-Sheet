
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>ans;
        Node *tail = head;
        Node *curr = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        while(curr->data < tail->data){
            if(curr->data + tail->data == target){
                ans.push_back({curr->data,tail->data});
                curr = curr->next;
                tail = tail->prev;
            }
            else if(curr->data + tail->data < target){
                curr = curr->next;
            }
            else tail = tail->prev;
        }
        return ans;

    }   

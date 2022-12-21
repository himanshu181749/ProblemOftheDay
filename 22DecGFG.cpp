class Solution{
    
public:
    Node* sortList(Node* head){
       Node* cur = head->next;
        Node* prev = head;
        
        while(cur)
        {
            if(cur->data < prev->data)
            {
                prev->next = cur->next;
                cur->next = head;
                head = cur;
                cur = prev;
            }
            else
            {
                // everthing is in right place
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

/**
Time = O(n)
Space= O(1)
**/

class Solution {
public:
    Node* flatten(Node* head) {
        
        explore(head);
        return head;
    }
    
    Node* explore(Node* cur){
        Node* lastNode = NULL;
        while(cur!=NULL){
            
            if(cur->child!=NULL){
                Node* next = cur->next;
                cur->next = cur->child;
                cur->child = NULL;
                cur->next->prev = cur;
                Node* end = explore(cur->next);
                end->next = next;
                if(next!=NULL)next->prev = end;
            }
            lastNode = cur;
            cur = cur->next;
        }
        return lastNode;
    }
};

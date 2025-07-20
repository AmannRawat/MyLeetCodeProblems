//LINKED LIST
// Not optimal Approach O(n) 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while (temp ->next->next != NULL) {
                temp->val=temp->next->val;
                temp = temp->next;
        }
        temp->val=temp->next->val;
        temp->next=NULL;
    }
};

//Optimal approach o(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
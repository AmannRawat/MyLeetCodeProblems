// More Space Complexity O(n) solution TC: O(n) using unordered map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode *,int> mpp;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()) return temp;
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    }
};

//Optimal solution Less Space Complexity O(1) solution TC: O(n)
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        while (t1 != NULL && t1->next != NULL) {
            t1 = t1->next->next;
            t2 = t2->next;
            if (t1 == t2)       // Can be exit when t1=NULL t2=NULL ex: [1]
                break;
        }
        if (t1 == NULL || t1->next == NULL) //NEED TO DETECT CYCLE 
            return NULL;
        t1 = head;
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};
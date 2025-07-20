//MY try (unsuccessful)
bool evenOdd(int d) { return d % 2 == 0; }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* temp = head;
        int count = 1;
        while (temp != NULL) {
            if (!evenOdd(count)) {
                swap(ptr->val, temp->val);
                ptr = temp;
            }
            temp = temp->next;
            count++;
        }
        return head;
    }

// better Approach Time Complexity : O(2N) Space complexity : O(N)
bool evenOdd(int d) { return d % 2 == 0; }
    ListNode* oddEvenList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        if (head == NULL || head->next == NULL)
            return head;
        while (temp != NULL && temp->next != NULL) {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) // if odd elm this insures we not miss last elm
            v.push_back(temp->val);
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) // EdgeCase
            v.push_back(temp->val);
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }

// Optimal approach Time Complexity : O(2N) Space complexity : O(1)
//LINKING UNLINKING
class Solution {
public:
    bool evenOdd(int d) { return d % 2 == 0; }
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* oddtemp = head;
        ListNode* evenhead = head->next;
        ListNode* eventemp = evenhead;
        // while (oddtemp != NULL && oddtemp->next != NULL) {
        //     oddtemp->next=oddtemp->next->next;
        //     oddtemp=oddtemp->next;
        // }
        while (eventemp != NULL && eventemp->next != NULL) {
            oddtemp->next = oddtemp->next->next;       //Even will be always ahead of odd
            eventemp->next = eventemp->next->next;
            oddtemp = oddtemp->next;
            eventemp = eventemp->next;
        }
        oddtemp->next = evenhead;
        return head;
    }
};
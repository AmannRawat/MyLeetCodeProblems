//Brute Force Sorting without Extra Space but time limit exceeded
 ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* current = NULL;
        ListNode* index = NULL;
        int temp;
        for (current = head; current != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->val > index->val) {
                    // Swap the val
                    temp = current->val;
                    current->val = index->val;
                    index->val = temp;
                }
            }
        }
        return head;
    }

// better Approach Space Complexity O(n) Solution TC : O(n logn)
ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }

// Optimal Approach Space Complexity O(1) Solution TC : O(n logn)

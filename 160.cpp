//Brute force Hshing TC: O(2N) SC:O(N)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        unordered_map<ListNode*, int> mpp;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != NULL) {
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            if (mpp.find(temp2) != mpp.end()) {
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }

//Better Approach TC: O(N1 + N2) SC:O(N)
ListNode* inter_point(ListNode* h1, ListNode* h2,int d) {
        while(d){
            d--;
            h1=h1->next;
        }
        while(h1!=NULL && h2!=NULL){
            if(h1==h2)return h1;
            h1=h1->next;
            h2=h2->next;
        }
        return NULL;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int l1 = 0, l2 = 0;
        while (temp1 != NULL) {
            l1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            l2++;
            temp2 = temp2->next;
        }
        if (l1 > l2)
            return inter_point(headA, headB, l1 - l2);
        else
            return inter_point(headB, headA, l2 - l1);

        return NULL;
    }

//Optimal Appraoch  TC: O(N1 + N2) SC:O(N)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == temp2)
                return temp1;
            if (temp1 == NULL)
                temp1 = headB;
            if (temp2 == NULL)
                temp2 = headA;
        }
        return temp1;
    }
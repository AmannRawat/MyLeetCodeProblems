//Naive Approach using HashMap TC: O(2N) SC:O(N) + O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Coping nodes into hash map
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;
        while (temp != NULL) {
            Node* nn = new Node(temp->val);
            mpp[temp] = nn;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {  
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];        //mpp[temp]->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};

//Optimal Solution TC: O(3N) SC:O(N)
Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* temp = head;
        while (temp != NULL) {
            Node* nn = new Node(temp->val);
            nn->next = temp->next;
            temp->next = nn;
            temp = temp->next->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* copy = dummy;
        temp = head;
        while (temp != NULL) {
            copy->next = temp->next;
            temp->next = temp->next->next;
            copy = copy->next;
            temp = temp->next;
        }
        return dummy->next;
    }
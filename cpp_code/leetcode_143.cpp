/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revert_list(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        ListNode* root = new ListNode(0);
        root->next = head;
        
        ListNode* pre = head;
        ListNode* cur = pre->next;
        while(cur) {
            pre->next = cur->next;
            cur->next = root->next;
            root->next = cur;
            cur = pre->next;
        }
        return root->next;
    }
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        if (head->next == NULL)
            return;
        
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count = count + 1;
            temp = temp->next;
        }
        if (count == 2)
            return;

        temp = head;
        for (int i = 0; i < (count + 1) / 2 - 1; i++) {
            temp = temp->next;
        }
        ListNode* headA = head;
        ListNode* headB = temp->next;
        temp->next = NULL;
        
        headB = revert_list(headB);
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(headA && headB) {
            curA = headA->next;
            curB = headB->next;

            headB->next = headA->next;
            headA->next = headB;

            headA = curA;
            headB = curB;
        }
    }
};

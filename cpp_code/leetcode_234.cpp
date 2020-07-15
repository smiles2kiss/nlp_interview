/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* revert_list(ListNode* head) {
        if (head == NULL)
            return head;
        
        ListNode* root = new ListNode(0);
        root->next = head;

        ListNode* pre = head;
        ListNode* cur = head->next;

        while(cur) {
            pre->next = cur->next;
            cur->next = root->next;
            root->next = cur;
            cur = pre->next;
        }
        return root->next;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        if (head->next == NULL)
            return true;

        vector<int> numA;
        vector<int> numB;
        ListNode* headA = head;
        while(headA) {
            numA.push_back(headA->val);
            headA = headA->next;
        }
        ListNode* headB = revert_list(head);
        while(headB) {
            numB.push_back(headB->val);
            headB = headB->next;
        }
        
        for (int i = 0; i < numA.size(); i++) {
            if (numA[i] != numB[i])
                return false;
        }
        return true;
    }
};

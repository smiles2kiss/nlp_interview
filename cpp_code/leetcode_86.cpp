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
    ListNode* partition(ListNode* head, int x) {
        // 数组中，双指针
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        int flag1 = 0;
        int flag2 = 0;
        ListNode* temp = head;
        while(temp) {
            if (temp->val >= x)
                flag1 = 1;
            if (temp->val < x)
                flag2 = 1;
            temp = temp->next;
        }
        if (flag1 == 1 && flag2 == 0) 
            return head;
        if (flag1 == 0 && flag2 == 1)
            return head;
        
        ListNode* small_cur = new ListNode(0);
        small_cur->next = head;
        ListNode* root = small_cur;

        ListNode* big_pre = small_cur;
        ListNode* big_cur = small_cur->next;
        while (big_cur && big_cur->val < x) {
            small_cur = small_cur->next;
            big_pre = big_pre->next;
            big_cur = big_cur->next;
        }

        while(big_cur) {
            if (big_cur->val >= x) {
                big_pre = big_pre->next;
                big_cur = big_cur->next;
            } else {
                big_pre->next = big_cur->next;
                big_cur->next = small_cur->next;
                small_cur->next = big_cur;
                small_cur = big_cur;
                big_cur = big_pre->next;
            }
        }
        return root->next;
    }
};

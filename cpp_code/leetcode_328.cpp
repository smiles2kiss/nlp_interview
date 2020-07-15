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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        
        ListNode* pre = head;
        ListNode* cur = head->next;

        vector<int> num;
        int count = 1;
        while(cur) {
            count = count + 1;
            if (count % 2 == 0) {
                num.push_back(cur->val);
                pre->next = cur->next;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        for (int i = 0; i < num.size(); i++) {
            ListNode* temp = new ListNode(num[i]);
            pre->next = temp;
            pre = temp;
        }
        return head;
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针
        if (head == NULL)
            return NULL;
        
        ListNode* pre = head;
        ListNode* cur = head;
        ListNode* first = NULL;
        ListNode* res = head;

        // 找到第一个入圈的位置，如果pre下次刚好到达该位置，则已运行一圈
        int flag = 0;
        while(cur && pre && pre->next) {
            cur = cur->next;
            pre = pre->next->next;
            if (cur == pre) {
                flag = 1;
                first = pre;
                break;
            }
        }
        if (flag == 0)
            return NULL;

        while(cur) {
            if (cur == res)
                return res;
            if (cur == first)
                res = res->next;
            cur = cur->next;
        }
        return res;
    }
};

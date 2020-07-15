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
        // ����ָ��
        if (head == NULL)
            return NULL;
        
        ListNode* pre = head;
        ListNode* cur = head;
        ListNode* first = NULL;
        ListNode* res = head;

        // �ҵ���һ����Ȧ��λ�ã����pre�´θպõ����λ�ã���������һȦ
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

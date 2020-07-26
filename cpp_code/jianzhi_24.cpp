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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        // ˼·
		// ��ʼ��root�ڵ���ͷ�ڵ㣬temp�ڵ�Ϊ��
		// ÿ��ɨ�赽head�ĺ�һ���ڵ�temp����temp���뵽root֮ǰ��������root�ڵ��ֵ 
		// ��ʼ����head��ͣ����ԭʼͷ�ڵ��λ�� 
        ListNode* root = head;
        ListNode* temp = head;
        while (head->next) {
            temp = head->next;
            head->next = temp->next;
            temp->next = root;
            root = temp;
        }
        return root;
    }
};

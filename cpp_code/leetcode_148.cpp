// ��������
// �鲢���� 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // ˼·: ����ð�������˼�룬˳��ɨ�����������ǰ�ڵ����һ���ڵ��ֵ���򽻻������ڵ��ֵ
 // ʱ�临�Ӷ�O(n*n)���ᳬʱ 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        
        ListNode* root = head;
        while (true) {
            int flag = 0;
            head = root;
            while (head->next) {
                if (head->val > head->next->val) {
                    int temp = head->val;
                    head->val = head->next->val;
                    head->next->val = temp;
                    flag = 1;
                }
                head = head->next;
            }
            if (flag == 0)
                break;
        }
        return root;
    }
};

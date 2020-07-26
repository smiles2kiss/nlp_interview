// 快速排序
// 归并排序 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 思路: 类似冒泡排序的思想，顺序扫描链表，如果当前节点比下一个节点的值大，则交换两个节点的值
 // 时间复杂度O(n*n)，会超时 
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

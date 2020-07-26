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
    ListNode* create_list(vector<int> nums) {
        int len = nums.size();
        if (len == 0) return NULL;

        ListNode* head = new ListNode(nums[0]);
        ListNode* root = head;
        for (int i = 1; i < len; i++) {
            ListNode* temp = new ListNode(nums[i]);
            head->next = temp;
            head = temp;
        }
        return root;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        // 快慢指针找出链表中点
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(mergeSort(head), mergeSort(slow));
    }

    // 有序链表的合并
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* head = new ListNode(0);
        ListNode* root = head;

        while (head1 && head2) {
            if (head1->val <= head2->val) {
                head->next = head1;
                head = head1;
                head1 = head1->next;
            } else {
                head->next = head2;
                head = head2;
                head2 = head2->next;
            }
        }
        head->next = head1 == NULL ? head2 : head1;
        return root->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        ListNode* root = mergeSort(head);
        return root;
    }
};

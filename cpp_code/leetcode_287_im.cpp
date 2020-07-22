class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // ����ָ��
        // ��i���ӵ�nums[i]�У���ȷ��һ��ѭ��
        // idx: [0, 1, 2, 3, 4]
        // num: [1, 3, 4, 2, 2]
        // 0 -> 1 -> 3 -> 2 -> -> 4 -> 2
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

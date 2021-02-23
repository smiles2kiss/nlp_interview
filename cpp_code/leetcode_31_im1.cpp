class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void nextPermutation(vector<int>& nums) {
        // [5,6,11,9,7,5,3,1]
        // �ҵ���һ������ǰһ�����ֵ�λ��,idx=2, num=11
        int len = nums.size();
        int idx = -1;
        for (int i = len-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // ��2��β���������У��ҵ���һ������6��ֵ
        int pos = idx;
        for (int i = len-1; i >= idx; i--) {
            if (nums[i] > nums[idx-1]) {
                pos = i;
                break;
            }
        }
        
        // ����7��6����Ԫ��
        swap(nums[idx-1], nums[pos]);
        // ��11֮���Ԫ�����°�����������
        sort(nums.begin() + idx, nums.end());
    }
};

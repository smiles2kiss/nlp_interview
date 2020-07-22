class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // ����Ȿ�������ҳ�����
        int n = nums.size();
        int result;
        int start = 0;
        int end = n - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid)
                    cnt = cnt + 1;
            }
            if (cnt <= mid) { // ��mid�ұ�Ѱ��
                start = mid + 1;
            } else {
                end = mid - 1;
                result = mid;
            }
        }
        return result;
    }
};

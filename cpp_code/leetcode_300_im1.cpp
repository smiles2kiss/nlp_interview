class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int len = 1;
        int n = nums.size();
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > d[len]) {
                len = len + 1;
                d[len] = nums[i];
            } else {
                // �ҵ������λ�ã���Ҫ��midԪ�ش�
                int left = 1;
                int right = len;
                int pos = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                // ��Ҫ�滻��ĳ��ֵ
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

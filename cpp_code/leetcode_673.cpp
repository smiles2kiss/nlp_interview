class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // ��̬�滮�ҵ����������е���󳤶�
        int len = nums.size();
        if (len == 1) return len;
        vector<int> length(len, 1);  // ����������е���󳤶�
        vector<int> count(len, 1);   // ����������е����ֵ
        
        // ��iΪ��㣬jΪ�յ�������������еĳ���
        int max_len = 1;
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[j] > nums[i]) {
                    if (length[j] < length[i] + 1) {
                        length[j] = length[i] + 1;
                        count[j] = count[i];
                    } else if (length[j] == length[i] + 1) {
                        count[j] = count[j] + count[i];
                    }
                }
                if (length[j] > max_len)
                    max_len = length[j];
            }
        }

        int max_num = 0;
        for (int i = 0; i < len; i++) {
            if (length[i] == max_len) {
                max_num = max_num + count[i];
            }
        }
        return max_num;
    }
};

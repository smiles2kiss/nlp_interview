class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        // ��i��β�������ڶ����к��½��ڶ����еĳ���
        // ���ڵ�i��λ��Ԫ���������Ļ����½���
        vector<int> up;
        vector<int> down;
        for (int i = 0; i < nums.size(); i++) {
            up.push_back(1);
            down.push_back(1);
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                // ��ǰ�ڵ���Ϊ���壬�ҵ���һ������
                up[i] = max(up[i-1], down[i-1] + 1);
                // down[i] = down[i-1]; // �Ժ󲻻ᾭ�������Ϊup[i]�Ѿ�����down[i]
            } 
            else if (nums[i] < nums[i - 1]) {
                // ��ǰ�ڵ���Ϊ���ȣ��ҵ���һ������
                down[i] = max(up[i - 1] + 1, down[i - 1]);
                // up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(down[nums.size() - 1], up[nums.size() - 1]);
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> data(len + 2, 1);
        for (int i = 1; i <= len; i++) 
            data[i] = nums[i-1];
        
        // ���嶯̬�滮ת�Ʒ���
        vector<vector<int>> dp;
        for (int i = 1; i <= len + 2; i++) {
            vector<int> temp(len + 2, 0);
            dp.push_back(temp);
        }

        for (int n = 3; n <= len + 2; n++) {
            // n ��ʾ������ĳ��ȣ���ΧΪ(3, len + 2)
            // ������ĳ���Ϊ3ʱ������������ֻ��һ��Ԫ��
            // ������ĳ���Ϊlen+2ʱ��������������len��Ԫ��
            for (int start = 0; start <= len + 2 - n; start++) {
                // ��n = 3Ϊ����
                // ���������� start ��ȡֵ��ΧΪ(0, len - 1)
                // ��������յ�λ�ÿɱ�ʾΪstart + n - 1
                // start = 0 ʱ������
                //   ������������data����ĵ�0��λ�ã���λ�õ�Ԫ�ز�������nums�����У���һ��λ��Ϊnums����ĵ�һ��Ԫ��
                //   ��������յ���data����ĵ�0 + n��λ��           
                // start = len - 1ʱ������
                //   ������������data����ĵ�len - 1��λ�ã���len��λ��Ϊnums��������һ��Ԫ��
                //   ��������յ���data����ĵ�len + 1��λ�ã���λ�õ�Ԫ�ز�������nums������
                for (int k = start + 1; k < start + n - 1; k++) {
                    // j �������һ�������Ƶ�Ԫ��λ��
                    int end = start + n - 1;

                    int left = dp[start][k];
                    int right = dp[k][end];
                    int sum = left + data[start] * data[k] * data[end] + right;
                    dp[start][end] = max(dp[start][end], sum);
                }
            }
        }
        return dp[0][len + 1]; 
    }
};

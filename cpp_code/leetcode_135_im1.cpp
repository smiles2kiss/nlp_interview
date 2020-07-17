class Solution {
public:
    int candy(vector<int>& ratings) {
        // ���ȸ�ÿ�����Ӷ�Ԥ�ȷ���һ���ǹ�
        int n = ratings.size();
        
        // �����ұ�֤�÷ָ��ߵĺ��ӻ�ø�����ǹ�
        // ���ҵ���֤�÷���ߵĺ��ӻ�ø�����ǹ�
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left2right[i] = left2right[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i+1] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // ȡ���ֵ����ڵ�i�ȴ������ھӣ�Ҳ�������ھ�
            sum = sum + max(left2right[i], right2left[i]);
        }
        return sum;
    }
}; 

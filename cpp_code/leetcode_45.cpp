class Solution {
public:
    int jump(vector<int>& nums) {
		int num = 0;
        int end = 0;
        int max_position = 0;
		int len = nums.size();

        // end�������ܹ����������λ�ã��п��ܳ���nums�ĳ���
		for (int i = 0; i < len - 1; i++) {
            max_position = max(max_position, i + nums[i]);
            if (i == end) {
                end = max_position;
                num = num + 1;
            }
        }
		return num; 
    }
};

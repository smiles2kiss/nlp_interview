class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int len = nums.size();
        // chain: 3������3�����ϵ���������
        unordered_map<int, int> num_count;  // ԭ����������i���ֵĴ���
        unordered_map<int, int> tail;       // ������i��β�ķ�����������������и���
        for (auto num: nums) num_count[num]++;
        for (auto num: nums) {
            if (num_count[num] == 0) continue;
            else if (num_count[num] > 0 && tail[num - 1] > 0) {
                num_count[num]--;
                tail[num-1]--;
                tail[num]++;
            }
            else if (num_count[num] > 0 && num_count[num + 1] > 0 && num_count[num + 2] > 0) {
                num_count[num]--;
                num_count[num + 1]--;
                num_count[num + 2]--;
                tail[num+2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

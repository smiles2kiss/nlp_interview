class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int len = nums.size();
        // chain: 3个或者3个以上的连续数组
        unordered_map<int, int> num_count;  // 原数组中数字i出现的次数
        unordered_map<int, int> tail;       // 以数字i结尾的符合题意的连续子序列个数
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

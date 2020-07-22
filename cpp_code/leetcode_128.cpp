class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto num: nums) {
            num_set.insert(num);
        }

        int max_len = 0;
        for (auto num: num_set) {
            if (!num_set.count(num - 1)) {
                int cur_num = num;
                int cur_len = 1;

                while (num_set.count(cur_num + 1)) {
                    cur_num = cur_num + 1;
                    cur_len = cur_len + 1;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};

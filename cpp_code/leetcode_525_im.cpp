class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        unordered_map<int, int> hash_table;
        hash_table[0] = 0;
        int x = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1)
                x++;
            else
                x--;
            // 两部分和相等，则说明中间比存在为0的子区间
            if (hash_table.find(x) != hash_table.end())
                ans = max(ans, i + 1 - hash_table[x]);
            else
                hash_table[x] = i + 1; // 代表第i个元素
        }
        return ans;
    }
};

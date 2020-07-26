class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> hash_map;
        int len = nums.size();
        hash_map[0] = -1;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum + nums[i];
            if (k != 0) sum = sum % k;
            if (hash_map.find(sum) != hash_map.end()) {
                if (i - hash_map[sum] > 1) // 找到两个同余的数
                    return true;
            } else {
                hash_map[sum] = i;
            }
        }
        return false;
    }
};

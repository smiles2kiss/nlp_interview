class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] == k ? 1 : 0;

        // pre[i]表示[0, .., i]中所有元素的和
        unordered_map<int, int> hash_map;
        hash_map[0] = 1;
        int count = 0, pre = 0;
        for (auto num: nums) {
            pre = pre + num;
            if (hash_map.find(pre - k) != hash_map.end()) 
                count += hash_map[pre - k];
            hash_map[pre]++;
        }
        return count;
    }
};

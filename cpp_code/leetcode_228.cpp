class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> results;
        int len = nums.size();
        if (len == 0) return results;
        if (len == 1) {
            results.push_back(to_string(nums[0]));
            return results;
        }
        int start = nums[0];
        int end = nums[0];
        string result;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i-1] + 1) {
                end = nums[i];
            } else {
                if (start < end) result = to_string(start) + "->" + to_string(end);
                else result = to_string(end);
                results.push_back(result);
                start = nums[i];
                end = nums[i];
            }

            if (i == nums.size() - 1) {
                if (start < end) result = to_string(start) + "->" + to_string(end);
                else result = to_string(end);
                results.push_back(result);
            }
        }
        return results;
    }
};

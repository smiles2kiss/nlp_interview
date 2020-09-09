class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, int start, vector<int> &track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
};

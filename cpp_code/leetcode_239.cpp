class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> res;
        if (k == 0) return res;
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};

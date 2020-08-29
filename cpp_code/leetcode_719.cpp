class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> small_heap;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(nums[j] - nums[i]);
                small_heap.push(dis);
            }
        }
        if (k > small_heap.size()) k = small_heap.size();
        while (k > 1) {
            small_heap.pop();
            k = k - 1;
        }
        return small_heap.top();
    }
};

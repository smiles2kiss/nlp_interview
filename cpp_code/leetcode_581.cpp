class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        // 建立小根堆
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;
        for (int i = 0; i < n; i++) heap.push(make_pair(nums[i], i));
        int start = -1, end = -1;
        while (!heap.empty()) {
            pair<int, int> item = heap.top();
            int idx1 = item.second;
            int idx2 = nums.size() - heap.size();
            if (idx1 > idx2 && start == -1) {start = idx2;}
            if (idx1 < idx2) {end = idx2;}
            heap.pop();
        }
        if (start == -1 && end == -1)
            return 0;
        else
            return end - start + 1;
    }
};

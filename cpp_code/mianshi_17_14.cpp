class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> small_heap;
        for (auto num:arr) small_heap.push(num);
        vector<int> nums;
        while (k > 0) {
            nums.push_back(small_heap.top());
            small_heap.pop();
            k = k - 1;
        }
        return nums;
    }
};

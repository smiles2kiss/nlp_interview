class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        // 最小堆 (根节点的值最小)，堆的大小最大为k 
		priority_queue<int, vector<int>, greater<int>> heap;
        for (auto num: nums) {
            if (heap.size() == k && heap.top() >= num)
                continue;
            if (heap.size() == k) 
                heap.pop();
            heap.push(num);  
        }
        return heap.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        // ��С�� (���ڵ��ֵ��С)���ѵĴ�С���Ϊk 
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

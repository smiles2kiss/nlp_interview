class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue;
        for (auto num: stones) queue.push(num);
        while (queue.size() > 1) {
            int top1 = queue.top(); queue.pop();
            int top2 = queue.top(); queue.pop();
            if (top1 != top2) 
                queue.push(top1 - top2);
        }
        return queue.size() == 1 ? queue.top() : 0;
    }
};

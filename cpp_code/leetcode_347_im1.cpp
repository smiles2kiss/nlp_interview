class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map; // first: 元素, second: 元素个数
        for (int num: nums) map[num]++;
        // 最小堆, first: 元素, second: 元素个数
        // 倒序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        for (auto iter: map) {
            if (q.size() == k) {// 队列满
                if (iter.second > q.top().first) { // 堆排序
                    q.pop();
                    q.push(make_pair(iter.second, iter.first));
                }
            } else {
                q.push(make_pair(iter.second, iter.first));
            }
        }
        // 输出的结果为倒序
        vector<int> result;
        while(q.size()) { //将优先队列中k个高频元素存入vector
            result.push_back(q.top().second);
            q.pop();
        }
        return vector<int>(result.rbegin(), result.rend());
    }
};

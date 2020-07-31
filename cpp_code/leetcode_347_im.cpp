class Solution {
public:
    struct cmp {
        // 小根堆
        bool operator() (const pair<int, int> &op1, const pair<int, int> &op2) {
            return op1.first > op2.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash_map; // first: 元素, second: 元素个数
        for (int num: nums) {
            if (hash_map.find(num) == hash_map.end())
                hash_map[num] = 1;
            else 
                hash_map[num] = hash_map[num] + 1;
        }

        // 小根堆: 根节点为最小值
        // 第一个元素为
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto iter: hash_map) {
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

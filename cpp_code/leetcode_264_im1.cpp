class Solution {
public:
    int nthUglyNumber(int n) {
        // 维护一个大小为3的小顶堆
        priority_queue<double, vector<double>, greater<double>> q;
        // 跟踪访问过的元素
        unordered_map<double, int> hash_table;
        double result = 1;

        q.push(1);
        hash_table.insert(make_pair(1, 1));
        for (int i = 1; i < n; i++) {
            if (hash_table.find(result*2) == hash_table.end()) {
                q.push(result*2);
                hash_table.insert(make_pair(result*2, 1));
            }
            if (hash_table.find(result*3) == hash_table.end()) {
                q.push(result*3);
                hash_table.insert(make_pair(result*3, 1));
            }
            if (hash_table.find(result*5) == hash_table.end()) {
                q.push(result * 5);
                hash_table.insert(make_pair(result*5, 1));
            }
            result = q.top();
            q.pop();
        }
        return q.top();
    }
};

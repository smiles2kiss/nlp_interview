class Solution {
public:
    int nthUglyNumber(int n) {
        // 维护一个大小为3的小顶堆
        priority_queue<double, vector<double>, greater<double>> q;
        // unordered_map<double, int> hash_table; // 跟踪访问过的元素
        set<int> s;
        double result = 1;

        q.push(1);
        s.insert(1);
        for (int i = 1; i < n; i++) {
            if (s.find(result*2) == s.end()) {
                q.push(result*2);
                s.insert(result*2);
            }
            if (s.find(result*3) == s.end()) {
                q.push(result*3);
                s.insert(result*3);
            }
            if (s.find(result*5) == s.end()) {
                q.push(result * 5);
                s.insert(result*5);
            }
            result = q.top();
            q.pop();
        }
        return q.top();
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int len = A.size();
        vector<int> sum(len + 1, 0);

        for (int i = 0; i < len; i++) 
            sum[i+1] = sum[i] + A[i];
        
        // 队头最小，队尾最大
        deque<int> q;
        int min_len = len + 1;
        for (int i = 0; i <= len; i++) {
            while (!q.empty() && sum[i] <= sum[q.back()])
                q.pop_back();
            while (!q.empty() && sum[i] - sum[q.front()] >= K) {
                min_len = min(min_len, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return min_len == len + 1 ? -1 : min_len;
	}
};

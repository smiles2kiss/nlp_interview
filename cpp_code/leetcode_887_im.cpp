class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) != memo.end()) 
            return memo[N * 100 + K];
        
        if (K == 0) return 0;
        if (K == 1) return N; // 顺序遍历 需要移动的次数

        int result;
        int left = 1;
        int right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            int t1 = dp(K-1, mid-1); // 鸡蛋在第mid层摔碎了
            int t2 = dp(K, N-mid);   // 鸡蛋在第mid层没摔碎
            if (t1 < t2) left = mid;
            else if (t1 > t2) right = mid;
            else {
                left = mid;
                right = mid;
            }

            result = 1 + min(
                max(dp(K-1, left-1),  dp(K, N-left)),  // 最多的尝试可能 
                max(dp(K-1, right-1), dp(K, N-right))
            );
            memo[N*100 + K] = result;
        }
        return memo[N * 100 + K];
    }
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
